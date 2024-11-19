#include "Stage.h"

#include"Player.h"
#include "DxLib.h"
#include <cassert>

namespace
{
	
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

	m_graphChipNumX = graphWidth / kChipWidth;
	m_graphChipNumY = GraphHeight / kChipHeight;
}

void Stage::End()
{
	// グラフィックの解放
	DeleteGraph(m_handle);
}

void Stage::Update(Player* player)
{
	for (int h = 0; h < kChipNumY; h++)
	{
		for (int w = 0; w < kChipNumX; w++)
		{
			int chipNo = kChipSetData[h][w];
			if (chipNo == 23 || chipNo == 287 || chipNo == 195)
			{
				if (player->GetLeft() >= w * kChipWidth && player->GetLeft() <= w * kChipWidth + kChipWidth
					&& player->GetTop() >= h * kChipHeight && player->GetTop() <= h * kChipHeight + kChipHeight)
				{
					// 下から当たった場合
					printfDx("HIT ");
					float chipBottom = h * kChipHeight + kChipHeight;
					player->AddMoveY(chipBottom - player->GetTop());
					player->OnCollideY();
					
					if (h * kChipHeight + kChipHeight <= player->GetTop())
					{
						// マップチップを壊す
						kChipSetData[h][w] = -1;
					}
				}
				// 上から当たった場合
				if (player->GetLeft() >= w * kChipWidth && player->GetLeft() <= w * kChipWidth + kChipWidth
					&& player->GetBottom() >= h * kChipHeight && player->GetBottom() <= h * kChipHeight + kChipHeight)
				{
					//printfDx("着地");
					float chipTop = h * kChipHeight;
					player->Landing(player->GetBottom() - chipTop);
					player->OnCollideY();
				}
				
			}
		}
	}
}

void Stage::Draw()
{
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x191970, true);
	//DrawRectGraph(0, Game::kScreenHeight - kChipHeight,	// 切り出したグラフィックをどこに表示するのか
	//	0, 0, 16, 16,	// グラフィックのどの部分を切り取るか
	//	m_handle, true);
	// チップを画面全体に敷き詰める
	for (int y = 0; y < kChipNumY; y++)
	{
		for (int x = 0; x < kChipNumX; x++)
		{
			// データから配置するチップを決定する
			int chipNo = kChipSetData[y][x];

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

			DrawRectGraph(x * kChipWidth, y * kChipHeight,
				cutX, cutY, kChipWidth, kChipHeight,
				m_handle, true);
		}
	}
	
}
