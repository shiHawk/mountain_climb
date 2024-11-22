#include "Stage.h"

#include"Player.h"
#include "DxLib.h"
#include <cassert>

namespace
{
	bool Hitbottom = false;
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
	// �O���t�B�b�N�̓ǂݍ���
	m_handle = LoadGraph("data/image/map.png");
	assert(m_handle != -1);
	// �O���t�B�b�N�Ɋ܂܂��`�b�v���𐔂���
	int graphWidth = 0;
	int GraphHeight = 0;
	GetGraphSize(m_handle, &graphWidth, &GraphHeight);

	m_graphChipNumX = graphWidth / kChipWidth;
	m_graphChipNumY = GraphHeight / kChipHeight;
}

void Stage::End()
{
	// �O���t�B�b�N�̉��
	DeleteGraph(m_handle);
}

void Stage::Update(Player* player)
{
	for (int h = 0; h < kChipNumY; h++)
	{
		for (int w = 0; w < kChipNumX; w++)
		{
			int chipNo = kChipSetData[h][w];
			if (chipNo == 23 || chipNo == 287 || chipNo == 195 || chipNo == 1)
			{
				if (player->GetLeft() >= w * kChipWidth && player->GetLeft() <= w * kChipWidth + kChipWidth
					&& player->GetTop() >= h * kChipHeight && player->GetTop() <= h * kChipHeight + kChipHeight)
				{
					// �����瓖�������ꍇ
					//printfDx("HIT ");
					Hitbottom = true;
					float chipBottom = h * kChipHeight + kChipHeight;
					player->AddMoveY(chipBottom - player->GetTop());// �}�b�v�`�b�v�ƃv���C���[�̏d�Ȃ������������ɂ��炷
					player->OnCollideY();// m_velocity.y��0�ɂ���
					if (h * kChipHeight + kChipHeight == player->GetTop() && player->FallFlag() == false)
					{
						// �}�b�v�`�b�v����
						kChipSetData[h][w] = -1;
					}
				}
				// �ォ�瓖�������ꍇ
				if (player->GetLeft() >= w * kChipWidth && player->GetLeft() <= w * kChipWidth + kChipWidth
					&& player->GetBottom() >= h * kChipHeight && player->GetBottom() <= h * kChipHeight + kChipHeight)
				{
					//printfDx("���n");
					float chipTop = h * kChipHeight;
					player->Landing(player->GetBottom() - chipTop);// �}�b�v�`�b�v�ƃv���C���[�̏d�Ȃ�����������ɂ��炷
					player->OnCollideY();	
				}

				// �}�b�v�`�b�v�̍������瓖�������ꍇ
				if (player->GetRight() >= w * kChipWidth && player->GetRight() < w * kChipWidth + kChipWidth
					&& player->GetTop() >= h * kChipHeight && player->GetTop() <= h * kChipHeight + kChipHeight
					&& Hitbottom == false)
				{
					float chipLeft = w * kChipWidth;
					player->AddMoveLeft(player->GetRight() - chipLeft);// �}�b�v�`�b�v�ƃv���C���[�̏d�Ȃ������������ɂ��炷
					player->OnCollideX();// m_velocity.x��0�ɂ���
				}
				// �}�b�v�`�b�v�̉E�����瓖�������ꍇ
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

				// �ォ�瓖�������ꍇ
				if (player->GetLeft() >= w * kChipWidth && player->GetLeft() <= w * kChipWidth + kChipWidth
					&& player->GetBottom() >= h * kChipHeight && player->GetBottom() <= h * kChipHeight + kChipHeight
					&& player->FallFlag() == true)
				{
					float chipTop = h * kChipHeight;
					if (player->PlayerAirPos() < chipTop)
					{
						player->Landing(player->GetBottom() - chipTop);
						player->OnCollideY();
					}
				}

				// �}�b�v�`�b�v�̍������瓖�������ꍇ
				if (player->GetRight() == w * kChipWidth && player->GetRight() < w * kChipWidth + kChipWidth
					&& player->GetTop() >= h * kChipHeight && player->GetTop() <= h * kChipHeight + kChipHeight)
				{
					float chipLeft = w * kChipWidth;
					player->AddMoveLeft(player->GetRight() - chipLeft);
					player->OnCollideX();
				}
				Hitbottom = false;
			}
		}
	}
}

void Stage::Draw()
{
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x191970, true);
	//DrawRectGraph(0, Game::kScreenHeight - kChipHeight,	// �؂�o�����O���t�B�b�N���ǂ��ɕ\������̂�
	//	0, 0, 16, 16,	// �O���t�B�b�N�̂ǂ̕�����؂��邩
	//	m_handle, true);
	// �`�b�v����ʑS�̂ɕ~���l�߂�
	for (int y = 0; y < kChipNumY; y++)
	{
		for (int x = 0; x < kChipNumX; x++)
		{
			// �f�[�^����z�u����`�b�v�����肷��
			int chipNo = kChipSetData[y][x];

			if (chipNo < 0)
			{
				// continue�͌J��Ԃ���(for,wihle)�̒��Ŏg�p���閽��
				// continue���Ă΂ꂽ��ȍ~�̌J��Ԃ������͍s�킸�A���̃��[�v�Ɉڍs����
				continue;
			}

			// 0����n�܂�ʂ��ԍ���
			// �ォ�牽�ځA�����牽�ڂȂ̂��A�Ƃ������ɕϊ�����K�v������
			// �O���t�B�b�N�ɉ��`�b�v���܂܂�Ă��邩�A�Ƃ��������g�p����
			// �v�Z�ŋ��߂�
			int indexX = chipNo % m_graphChipNumX;	// �����牽�ڂ̃`�b�v��
			int indexY = chipNo / m_graphChipNumX;	// �ォ�牽�ڂ̃`�b�v��

			// �`�b�v�ԍ�����؂�o���ʒu���v�Z����
			int cutX = indexX * kChipWidth;
			int cutY = indexY * kChipHeight;

			DrawRectGraph(x * kChipWidth, y * kChipHeight,
				cutX, cutY, kChipWidth, kChipHeight,
				m_handle, true);
		}
	}
	
}
