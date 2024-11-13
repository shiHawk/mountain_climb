#pragma once
class Player;

class Stage
{
public:
	Stage();
	~Stage();

	void Init();	// 初期化
	void End();	// 終了
	void Update(Player* player);	// 更新
	void Draw();	// 描画
private:
	// グラフィックハンドル
	int m_handle;
	// グラフィックに含まれるチップ数
	int m_graphChipNumX;
	int m_graphChipNumY;
};

