#include "Stage.h"
#include "game.h"
#include "DxLib.h"
#include <cassert>

namespace
{
	// �}�b�v�`�b�v��1���̃T�C�Y
	constexpr int kChipWidth = 16;
	constexpr int kChipHeight = 16;

	// �}�b�v�ɕ~���l�߂�`�b�v�̐�
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

void Stage::Update()
{
}

void Stage::Draw()
{
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(160, 216, 239), true);
	//DrawRectGraph(0, Game::kScreenHeight - kChipHeight,	// �؂�o�����O���t�B�b�N���ǂ��ɕ\������̂�
	//	0, 0, 16, 16,	// �O���t�B�b�N�̂ǂ̕�����؂��邩
	//	m_handle, true);
	// �`�b�v����ʑS�̂ɕ~���l�߂�
	for (int y = 0; y < 1; y++)
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

			DrawRectGraph(x * kChipWidth, Game::kScreenHeight - kChipHeight,
				cutX, cutY, kChipWidth, kChipHeight,
				m_handle, true);
		}
	}
	
}
