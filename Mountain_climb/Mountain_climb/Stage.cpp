#include "Stage.h"

#include"Player.h"
#include "DxLib.h"
#include <cassert>

namespace
{
	bool hitBottom = false;
	float liftX = 0;
}

Stage::Stage() :
	m_graphChipNumX(0),
	m_graphChipNumY(0),
	m_handle(-1)
{
}

Stage::~Stage()
{
}

void Stage::Init()
{
	// グラフィックの読み込み
	m_handle = LoadGraph("data/image/map.png");
	assert(m_handle != -1);
	// グラフィックに含まれるチップ数を数える
	int graphWidth = 0;
	int GraphHeight = 0;
	GetGraphSize(m_handle, &graphWidth, &GraphHeight);
	//マップチップの数
	m_graphChipNumX = graphWidth / kChipWidth;
	m_graphChipNumY = GraphHeight / kChipHeight;
	//配列のマップデータをマップチップに入れる。
	for (int wIndex = 0; wIndex < m_graphChipNumX; wIndex++)
	{
		for (int hIndex = 0; hIndex < m_graphChipNumY; hIndex++)
		{
			MapChip& temp = m_map.mapChips[wIndex][hIndex];
			temp.w = kChipWidth;//幅
			temp.h = kChipHeight;//高さ
			temp.chipKind = kChipSetData[kChipNumY][kChipNumX];//種類
			//mapChipのposを決める
			float tempX = wIndex * temp.w + temp.w * 0.5f;
			float tempY = hIndex * temp.h + temp.w * 0.5f;
			temp.pos.SetPos(tempX,tempY);
		}
	}




}

void Stage::End()
{
	// グラフィックの解放
	DeleteGraph(m_handle);
}

void Stage::Update(Player* player, Score* score)
{
	for (int h = 0; h < kChipNumY; h++)
	{
		for (int w = 0; w < kChipNumX; w++)
		{
			int chipNo = kChipSetData[h][w];
			if (chipNo < 440 && chipNo >= 0)
			{
				if (player->GetLeft() >= w * kChipWidth && player->GetLeft() <= w * kChipWidth + kChipWidth
					&& player->GetTop() >= h * kChipHeight - m_AllChipHeight && player->GetTop() <= h * kChipHeight + kChipHeight - m_AllChipHeight)
				{
					// 下から当たった場合
					float chipBottom = h * kChipHeight + kChipHeight - m_AllChipHeight;
					player->AddMoveY(chipBottom - player->GetTop());// マップチップとプレイヤーの重なった分だけ下にずらす
					player->OnCollideY();// m_velocity.yを0にする
					if (h * kChipHeight + kChipHeight - m_AllChipHeight == player->GetTop() && player->FallFlag() == false
						&& player->GetPos().y > -240)
					{
						// マップチップを壊す
						kChipSetData[h][w] = -1;
						score->Update();
						int temp = score->DrawScore();
						printfDx("score:(%d)\n",temp);
					}
					hitBottom = true;
				}

				// 上から当たった場合
				if (player->GetLeft() >= w * kChipWidth && player->GetLeft() <= w * kChipWidth + kChipWidth
					&& player->GetBottom() >= h * kChipHeight - m_AllChipHeight && player->GetBottom() <= h * kChipHeight + kChipHeight - m_AllChipHeight)
				{
					//printfDx("着地");
					float chipTop = h * kChipHeight - m_AllChipHeight;
					player->Landing(player->GetBottom() - chipTop);// マップチップとプレイヤーの重なった分だけ上にずらす
					hitBottom = false;
					player->OnCollideY();	
				}

				// マップチップに左から当たった場合
				// 1マスの隙間からマップチップの下から当たると左側から当たった時の処理に引っかかって
				// プレイヤーが左にずれてしまう　一通り終わってから調整する
				if (player->GetRight() >= w * kChipWidth && player->GetRight() < w * kChipWidth + kChipWidth
					&& player->GetTop() >= h * kChipHeight - m_AllChipHeight && player->GetTop() <= h * kChipHeight + kChipHeight - m_AllChipHeight
					&& hitBottom == false)
				{
					float chipLeft = w * kChipWidth;
					player->AddMoveLeft(player->GetRight() - chipLeft);// マップチップとプレイヤーの重なった分だけ左にずらす
					player->OnCollideX();// m_velocity.xを0にする
				}
				
				// マップチップに右から当たった場合
				/*if (player->GetLeft() > w * kChipWidth && player->GetLeft() < w * kChipWidth + kChipWidth
					&& player->GetTop() >= h * kChipHeight && player->GetTop() <= h * kChipHeight + kChipHeight)
				{
					float chipRight = w * kChipWidth + kChipWidth;
					player->AddMoveRight(chipRight - player->GetLeft());
					player->OnCollideX();
				}*/
			}

			if (chipNo == 440 || chipNo == 441 || chipNo == 442)
			{
				// 上から当たった場合
				if (player->GetLeft() >= w * kChipWidth && player->GetLeft() <= w * kChipWidth + kChipWidth
					&& player->GetBottom() >= h * kChipHeight - m_AllChipHeight && player->GetBottom() <= h * kChipHeight + kChipHeight - m_AllChipHeight
					&& player->FallFlag() == true)
				{
					float chipTop = h * kChipHeight - m_AllChipHeight;
					if (player->PlayerAirPos() < chipTop)
					{
						player->Landing(player->GetBottom() - chipTop);
						player->OnCollideY();
					}
				}

				// マップチップの左側から当たった場合
				if (player->GetRight() == w * kChipWidth && player->GetRight() < w * kChipWidth + kChipWidth
					&& player->GetTop() >= h * kChipHeight && player->GetTop() <= h * kChipHeight + kChipHeight)
				{
					float chipLeft = w * kChipWidth;
					player->AddMoveLeft(player->GetRight() - chipLeft);
					player->OnCollideX();
				}
			}
		}
	}
}

void Stage::Draw(Camera* camera)
{
	// 背景
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x191970, true);

	// チップを画面全体に敷き詰める
	for (int hIndex = 0; hIndex < kChipNumY; hIndex++)
	{
		for (int wIndex = 0; wIndex < kChipNumX; wIndex++)
		{
			// データから配置するチップを決定する
			int chipNo = kChipSetData[hIndex][wIndex];

			if (chipNo < 0)
			{
				// continueは繰り返し文(for,wihle)の中で使用する命令
				// continueが呼ばれたら以降の繰り返し処理は行わず、次のループに移行する
				continue;
			}

			// 0から始まる通し番号を
			// 上から何個目、左から何個目なのか、という情報に変換する必要がある
			// グラフィックに何個チップが含まれているか、という情報を使用して
			// 計算で求める
			int indexX = chipNo % m_graphChipNumX;	// 左から何個目のチップか
			int indexY = chipNo / m_graphChipNumX;	// 上から何個目のチップか

			// チップ番号から切り出し位置を計算する
			int cutX = indexX * kChipWidth;
			int cutY = indexY * kChipHeight;

			//描画範囲の決定
			const MapChip& mapChip = m_map.mapChips[hIndex][wIndex];
			//1つのマップチップの四隅の座標
			/*auto leftTop = static_cast<int>(mapChip.pos.x - mapChip.w * 0.5f);
			auto leftBottom = static_cast<int>(mapChip.pos.y - mapChip.h * 0.5f);
			auto rightTop = static_cast<int>(mapChip.pos.x + mapChip.w * 0.5f);
			auto rightBottom = static_cast<int>(mapChip.pos.y + mapChip.h * 0.5f);*/

			/*DrawRectGraph(
				mapChip.pos.y, mapChip.pos.x,
				leftTop, leftBottom, leftTop - rightTop, leftTop - rightTop,
				m_handle, true);*/

			DrawRectGraph(wIndex * kChipWidth + static_cast<int>(camera->m_drawOffset.x),
				hIndex * kChipHeight - m_AllChipHeight + static_cast<int>(camera->m_drawOffset.y),
				cutX, cutY, kChipWidth, kChipHeight,
				m_handle, true);
		}
	}
	
}
