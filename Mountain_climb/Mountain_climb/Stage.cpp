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
	// �O���t�B�b�N�̓ǂݍ���
	m_handle = LoadGraph("data/image/map.png");
	assert(m_handle != -1);
	// �O���t�B�b�N�Ɋ܂܂��`�b�v���𐔂���
	int graphWidth = 0;
	int GraphHeight = 0;
	GetGraphSize(m_handle, &graphWidth, &GraphHeight);
	//�}�b�v�`�b�v�̐�
	m_graphChipNumX = graphWidth / kChipWidth;
	m_graphChipNumY = GraphHeight / kChipHeight;
	//�z��̃}�b�v�f�[�^���}�b�v�`�b�v�ɓ����B
	for (int wIndex = 0; wIndex < m_graphChipNumX; wIndex++)
	{
		for (int hIndex = 0; hIndex < m_graphChipNumY; hIndex++)
		{
			MapChip& temp = m_map.mapChips[wIndex][hIndex];
			temp.w = kChipWidth;//��
			temp.h = kChipHeight;//����
			temp.chipKind = kChipSetData[kChipNumY][kChipNumX];//���
			//mapChip��pos�����߂�
			float tempX = wIndex * temp.w + temp.w * 0.5f;
			float tempY = hIndex * temp.h + temp.w * 0.5f;
			temp.pos.SetPos(tempX,tempY);
		}
	}




}

void Stage::End()
{
	// �O���t�B�b�N�̉��
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
					// �����瓖�������ꍇ
					float chipBottom = h * kChipHeight + kChipHeight - m_AllChipHeight;
					player->AddMoveY(chipBottom - player->GetTop());// �}�b�v�`�b�v�ƃv���C���[�̏d�Ȃ������������ɂ��炷
					player->OnCollideY();// m_velocity.y��0�ɂ���
					if (h * kChipHeight + kChipHeight - m_AllChipHeight == player->GetTop() && player->FallFlag() == false
						&& player->GetPos().y > -240)
					{
						// �}�b�v�`�b�v����
						kChipSetData[h][w] = -1;
						score->Update();
						int temp = score->DrawScore();
						printfDx("score:(%d)\n",temp);
					}
					hitBottom = true;
				}

				// �ォ�瓖�������ꍇ
				if (player->GetLeft() >= w * kChipWidth && player->GetLeft() <= w * kChipWidth + kChipWidth
					&& player->GetBottom() >= h * kChipHeight - m_AllChipHeight && player->GetBottom() <= h * kChipHeight + kChipHeight - m_AllChipHeight)
				{
					//printfDx("���n");
					float chipTop = h * kChipHeight - m_AllChipHeight;
					player->Landing(player->GetBottom() - chipTop);// �}�b�v�`�b�v�ƃv���C���[�̏d�Ȃ�����������ɂ��炷
					hitBottom = false;
					player->OnCollideY();	
				}

				// �}�b�v�`�b�v�ɍ����瓖�������ꍇ
				// 1�}�X�̌��Ԃ���}�b�v�`�b�v�̉����瓖����ƍ������瓖���������̏����Ɉ�����������
				// �v���C���[�����ɂ���Ă��܂��@��ʂ�I����Ă��璲������
				if (player->GetRight() >= w * kChipWidth && player->GetRight() < w * kChipWidth + kChipWidth
					&& player->GetTop() >= h * kChipHeight - m_AllChipHeight && player->GetTop() <= h * kChipHeight + kChipHeight - m_AllChipHeight
					&& hitBottom == false)
				{
					float chipLeft = w * kChipWidth;
					player->AddMoveLeft(player->GetRight() - chipLeft);// �}�b�v�`�b�v�ƃv���C���[�̏d�Ȃ������������ɂ��炷
					player->OnCollideX();// m_velocity.x��0�ɂ���
				}
				
				// �}�b�v�`�b�v�ɉE���瓖�������ꍇ
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

				// �}�b�v�`�b�v�̍������瓖�������ꍇ
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
	// �w�i
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x191970, true);

	// �`�b�v����ʑS�̂ɕ~���l�߂�
	for (int hIndex = 0; hIndex < kChipNumY; hIndex++)
	{
		for (int wIndex = 0; wIndex < kChipNumX; wIndex++)
		{
			// �f�[�^����z�u����`�b�v�����肷��
			int chipNo = kChipSetData[hIndex][wIndex];

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

			//�`��͈͂̌���
			const MapChip& mapChip = m_map.mapChips[hIndex][wIndex];
			//1�̃}�b�v�`�b�v�̎l���̍��W
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
