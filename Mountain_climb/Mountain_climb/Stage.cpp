#include "Stage.h"
#include "game.h"
#include "DxLib.h"
#include <cassert>

namespace
{
	// マップチップの1つ分のサイズ
	constexpr int kChipWidth = 16;
	constexpr int kChipHeight = 16;

	// マップに敷き詰めるチップの数
	constexpr int kChipNumX = Game::kScreenWidth / kChipWidth;
	constexpr int kChipNumY = Game::kScreenHeight / kChipHeight;

	constexpr int kChipSetData[1][kChipNumX] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
}

Stage::Stage():
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

void Stage::Update()
{
}

void Stage::Draw()
{
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(160, 216, 239), true);
	//DrawRectGraph(0, Game::kScreenHeight - kChipHeight,	// 切り出したグラフィックをどこに表示するのか
	//	0, 0, 16, 16,	// グラフィックのどの部分を切り取るか
	//	m_handle, true);
	// チップを画面全体に敷き詰める
	for (int y = 0; y < 1; y++)
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

			DrawRectGraph(x * kChipWidth, Game::kScreenHeight - kChipHeight,
				cutX, cutY, kChipWidth, kChipHeight,
				m_handle, true);
		}
	}
	
}
