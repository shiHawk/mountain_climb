#pragma once
#include "game.h"
#include "Vec2.h"
#include "Camera.h"
class Player;

struct MapChip
{
	Vec2 pos;
	float w, h;
	int chipKind;
};


class Stage
{
public:
	Stage();
	~Stage();

	void Init();	// 初期化
	void End();	// 終了
	void Update(Player* player);	// 更新
	void Draw(Camera* camera);	// 描画
	int BrokenBlock();
	void ChangeStage();
	void ResetStage();
private:
	// グラフィックハンドル
	int m_handle;
	// グラフィックに含まれるチップ数
	int m_graphChipNumX;
	int m_graphChipNumY;

	// マップチップの1つ分のサイズ
	const static int kChipWidth = 16;
	const static int kChipHeight = 16;

	// マップに敷き詰めるチップの数
	const static int kChipNumX = Game::kScreenWidth / kChipWidth;
	const static int kChipNumY = 88;

	// 1階層の高さ
	int m_hierarchyHeight = 96;

	int m_fontHandle;

	// ステージ1
	int kChipSetData[kChipNumY][kChipNumX] =
	{
		{-1,-1,-1,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,110,112,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},//14層
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,110,111,111,112,-1,-1,-1,-1,-1,-1,-1,-1,110,111,111,112,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},//13層
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,110,111,111,112,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,110,111,111,111,112,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},//12層
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,440,441,441,441,441,441,442,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1},
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},//11層
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,48,49,49,51,110,111,111,111,111,111,112,-1,-1,-1,-1,-1,-1,110,111,111,111,112,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},//10層
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,440,441,441,441,441,441,442,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1},
		{48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51},//9層
		{48,49,49,51,-1,-1,-1,-1,110,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,112,-1,-1,-1,48,49,49,51},
		{48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51},
		{48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51},
		{77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79},
		{110,111,111,111,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,111,111,112},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},//8層
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{66,67,67,68,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,67,67,68},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5},
		{33,34,34,35,100,100,100,100,101,-1,-1,-1,99,100,100,101,-1,-1,-1,99,100,100,100,100,100,101,-1,-1,-1,-1,-1,99,100,100,100,100,33,34,34,35},//7層
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{66,67,67,68,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,67,67,68},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5},
		{33,34,34,35,-1,-1,-1,99,100,100,100,100,100,100,100,100,100,101,-1,-1,-1,99,100,100,100,100,100,100,100,100,100,100,101,-1,-1,-1,33,34,34,35},//6層
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{66,67,67,68,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,67,67,68},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5},
		{220,221,221,222,100,100,100,100,101,-1,-1,-1,99,100,100,100,101,-1,-1,-1,-1,99,100,100,100,100,101,-1,-1,-1,-1,99,100,100,100,100,220,221,221,222},//5層
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{253,254,254,255,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,253,254,254,255},
		{191,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195},
		{220,221,221,222,-1,256,-1,-1,-1,319,254,254,254,320,-1,-1,-1,319,254,254,254,320,-1,-1,319,254,254,254,320,-1,-1,-1,-1,319,254,320,220,221,221,222},//4層
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{253,254,254,255,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,253,254,254,255},
		{191,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195},
		{220,221,221,222,254,320,-1,319,254,254,254,254,320,-1,-1,-1,-1,-1,-1,-1,319,254,254,254,254,254,254,320,-1,-1,-1,-1,319,320,-1,-1,220,221,221,222},//3層
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{253,254,254,255,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,253,254,254,255},
		{286,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287},
		{55,60,60,62,-1,-1,-1,319,254,254,254,254,254,254,254,254,254,254,254,320,-1,-1,-1,-1,319,254,254,254,254,320,-1,-1,-1,319,254,320,55,60,60,62},//2層
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{88,89,89,90,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,88,89,89,90},
		{22,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,24},
		{55,60,60,62,-1,-1,121,122,123,-1,121,122,122,122,122,123,-1,121,122,122,122,123,-1,121,122,122,122,123,-1,121,122,122,122,123,-1,-1,55,60,60,62},//1層
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{88,89,89,90,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,88,89,89,90},
		{22,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,24}
	};


	// ステージ2
	int kChipSetData2[kChipNumY][kChipNumX] =
	{
		{-1,-1,-1,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},//14層
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,440,441,441,441,441,442,-1,-1 -1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},//13層
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,110,111,111,111,111,112,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,110,111,111,111,112,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},//12層
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,440,441,441,441,441,441,442,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1},
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},//11層
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,110,111,111,111,112,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},//10層
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,440,441,441,441,441,442,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1},
		{48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51},//9層
		{48,49,49,51,-1,-1,-1,-1,110,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,112,-1,-1,-1,48,49,49,51},
		{48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51},
		{48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51},
		{77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79},
		{110,111,111,111,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,111,111,112},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},//8層
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{66,67,67,68,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,67,67,68},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5},
		{33,34,34,35,99,101,-1,-1,99,100,100,100,100,100,100,101,-1,-1,-1,99,100,100,100,100,100,100,101,-1,-1,-1,-1,99,100,100,100,100,33,34,34,35},//7層
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{66,67,67,68,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,67,67,68},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5},
		{33,34,34,35,99,101,-1,-1,-1,-1,-1,99,100,100,100,100,100,101,-1,-1,-1,99,100,100,100,100,100,100,100,100,101,-1,-1,-1,-1,-1,33,34,34,35},//6層
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{66,67,67,68,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,67,67,68},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5},
		{220,221,221,222,100,100,100,100,100,101,-1,-1,-1,-1,-1,-1,99,100,100,100,100,101,-1,-1,-1,99,100,100,100,100,100,100,100,100,100,101,220,221,221,222},//5層
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{253,254,254,255,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,253,254,254,255},
		{191,195,195,195,-1,-1,-1,-1,-1,254,254,254,254,254,254,-1,-1,-1,-1,-1,254,254,254,254,254,254,-1,-1,-1,-1,-1,191,195,195,195,195,195,195,195,195},
		{220,221,221,222,-1,-1,-1,-1,-1,254,254,254,254,254,254,-1,-1,-1,-1,-1,254,254,254,254,254,254,-1,-1,-1,-1,-1,253,254,254,254,254,221,221,221,222},//4層
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{253,254,254,255,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,253,254,254,255},
		{191,195,195,195,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,191,195,195,195},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,286,287,287,288,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},//3層
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{253,254,254,255,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,253,254,254,255},
		{286,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287},
		{55,60,60,62,319,254,254,254,320,-1,-1,-1,319,254,254,320,-1,-1,-1,319,254,254,254,254,254,254,254,320,-1,-1,-1,319,254,254,254,320,55,60,60,62},//2層
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{88,89,89,90,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,88,89,89,90},
		{22,23,23,23,23,23,23,23,23,23,23,23,23,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,23,23,23,23,23,23,23,23,23,23,23,24},
		{55,60,60,62,-1,121,122,122,122,122,122,122,122,123,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,121,122,122,122,122,122,122,122,123,55,60,60,62},//1層
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{88,89,89,90,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,88,89,89,90},
		{22,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,24}
	};

	//ステージ3
	int kChipSetData3[kChipNumY][kChipNumX] =
	{
		{-1,-1,-1,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},//14層
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,440,441,441,441,441,442,-1,-1 - 1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},//13層
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,110,111,111,111,112,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1,-1},
		{-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,110,111,111,112,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},//12層
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,48,49,49,51,-1,-1,-1,440,441,441,442,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1,-1},
		{-1,-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1,-1},
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},//11層
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,110,111,111,112,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1,-1},
		{-1,-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},//10層
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,440,441,441,442,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51,-1},
		{-1,77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79,-1},
		{48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51},//9層
		{48,49,49,51,-1,-1,-1,-1,110,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,111,112,-1,-1,-1,110,111,111,111,111,112,-1,-1,-1,48,49,49,51},
		{48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51},
		{48,49,49,51,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,48,49,49,51},
		{77,78,78,79,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,77,78,78,79},
		{110,111,111,111,111,111,111,111,112,-1,-1,-1,-1,-1,110,111,112,-1,-1,-1,-1,-1,-1,-1,110,111,111,112,-1,-1,-1,-1,110,111,111,111,111,111,111,112},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},//8層
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{66,67,67,68,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,67,67,68},
		{0,1,1,1,1,1,1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,5},
		{33,34,34,35,99,100,101,-1,-1,-1,-1,99,100,101,-1,-1,-1,-1,99,100,101,-1,-1,-1,-1,99,100,101,-1,-1,-1,-1,99,100,101,-1,33,34,34,35},//7層
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{66,67,67,68,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,67,67,68},
		{0,1,1,2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,440,441,441,442,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,1,1,5},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},//6層
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{33,34,34,35,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,33,34,34,35},
		{66,67,67,68,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,66,67,67,68},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5},
		{220,221,221,222,100,101,-1,-1,-1,-1,99,100,100,100,100,100,100,100,101,-1,-1,-1,-1,-1,-1,99,100,100,100,100,100,100,100,100,100,101,220,221,221,222},//5層
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{253,254,254,255,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,253,254,254,255},
		{191,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195},
		{220,221,221,222,254,254,254,254,254,320,-1,-1,-1,319,254,254,320,-1,-1,-1,-1,319,254,254,254,254,320,-1,-1,-1,-1,253,254,254,254,254,221,221,221,222},//4層
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{253,254,254,255,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,253,254,254,255},
		{191,195,195,195,110,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,112,191,195,195,195},
		{220,221,221,222,254,320,-1,-1,-1,319,254,254,254,254,254,254,254,254,320,-1,-1,-1,319,254,320,-1,-1,-1,319,254,254,254,254,254,254,320,220,221,221,222},//3層
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{220,221,221,222,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,220,221,221,222},
		{253,254,254,255,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,253,254,254,255},
		{286,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287,287},
		{55,60,60,62,319,254,320,-1,-1,-1,-1,319,254,254,320,-1,-1,319,254,254,254,320,-1,-1,-1,-1,319,254,254,254,254,254,254,254,254,320,55,60,60,62},//2層
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{88,89,89,90,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,88,89,89,90},
		{22,23,23,23,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,440,441,441,441,441,442,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,23,23,23,24},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},//1層
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{55,60,60,62,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,55,60,60,62},
		{88,89,89,90,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,88,89,89,90},
		{22,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,24}
	};

	/// <summary>
/// マップ構造体
/// </summary>
	struct Map
	{
		MapChip mapChips[kChipNumY][kChipNumX];
	};

	Map m_map;

	/// <summary>
	/// マップチップ全体の左下をウィンドウの左下に合わせるための高さ調整用変数
	/// </summary>
	int m_AllChipHeight = (kChipNumY * kChipHeight) - Game::kScreenHeight;
	Player m_player;
};

