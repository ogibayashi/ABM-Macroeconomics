#include <stdio.h>
#include "CAppli.h"


void main()
{
	CAppli *cap;
	cap=new CAppli;
		
	cap->Create_Assumption();	//�p�����[�^�N���X�̐���
	cap->Set_Parameter();		//�p�����[�^�̃Z�b�g
	cap->Create_Market();		//Show�N���X�A�}�[�P�b�g�N���X�̐���
	cap->Create_file();			//�������ݗpFILE�̐���
	cap->Create_Agent();		//�G�[�W�F���g�̐����A�����l�ݒ�
	cap->Market();		//���ۂ̎��s

}