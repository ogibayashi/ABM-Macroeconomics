//CVextor_owner.h
#ifndef INC_CVECTOR_OWNER
#define INC_CVECTOR_OWNER
#include <stdio.h>
#include <vector>
//#include "CTest_agent.h"
//#include "CAccount.h"
using namespace std;

class CVector_owner
{
	vector <int > exp_vec;

	vector <int > statistics_kyuyo;	//����������^�����̏�ŋL�����ăv�����g�A�E�g�i����Ȃ���Ύ̂Ă�j
	vector <int > kyuyo_no;			//statistics_kyuyo�̃G�[�W�F���g�ԍ��ۑ�
	vector <int > sort_static_kyuyo;//���^�̃\�[�g�����G�[�W�F���g�i���o�[
	vector <int > statistics_income;	//���^�̑��v
	vector <int > new_inmoney;
	vector <CProduct_class *> mem_class_statics;//�s��̏���҂̍w�����i�ʓ��v�f�[�^�̏W��
	vector <CProduct_class *> mem_class_statics_w;//�z�[���Z���[�̍w�����i�ʓ��v�f�[�^�W��
	vector <CProduct_class *>::iterator del_pc;
	vector <CProduct_class *> mem_class_stock_statics;//�s��̃��e�C���[�݌ɐ��i�ʓ��v�f�[�^�̏W��
	vector <CProduct_class *> mem_class_stock_statics_w;//�s��̃z�[���Z���[�݌ɐ��i�ʓ��v�f�[�^�W��


public:

	void Set_test_agent();
	void Set_test_exp_vec();
	vector<int > Get_test_exp_vec(){return exp_vec;};
	void print_exp_vec();

};




#endif