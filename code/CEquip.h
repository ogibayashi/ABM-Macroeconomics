//CAccount.h
#ifndef INC_CEquip
#define INC_CEquip
#include <stdio.h>
#include <vector>
#include"CParameter.h"
#include"CTax.h"
#include"CRandum.h"

using namespace std;

class CEquip
{
	vector <int> repay_principal;		//�ݔ��������̊����̒����ؓ����̕ԍό��{�z
	vector <int> repay_intereset;		//�ݔ��������̊����̒����ؓ����̕ԍϗ��q�z
	vector <int> depreciation;			//�ݔ��̊����̌������p�z
	int set_period;

public:
	void Set_set_period(int period){set_period=period;};
	int Get_set_period(){return set_period;};
	void Set_repay_principal(int amount){repay_principal.push_back(amount);};		//CBank�̊֐��ŌĂяo��
	void Set_repay_interest(int amount){repay_intereset.push_back(amount);};		//CBank�̊֐��ŌĂяo��
	void Set_depreciation(int amount){depreciation.push_back(amount);};				//CBank�̊֐��ŌĂяo��


	int Inv_get_loan_l_data(){return repay_principal.size();};
	int Inv_get_loan_l_number()
	{				//�ؓ��W���ɃT�C�Y������ꍇ��1��Ԃ�
		int x=0;
		if(repay_principal.size()>0) x=1;
		return x;
	};

	int Inv_get_loan_amount()
	{
		int amount=0;
		if(repay_principal.size()>0)	amount=repay_principal[0];
		return amount;
	};
	int Inv_get_inte()
	{
		int amount=0;
		if(repay_intereset.size()>0)	amount=repay_intereset[0];
		return amount;
	};
	int Inv_get_depreciation()
	{
		int amount=0;
		if(depreciation.size()>0)	amount=depreciation[0];
		return amount;
	}

	void Inv_repayment()
	{
		if(repay_principal.size()>0)
		{
			vector <int> ::iterator lo;
			vector <int> ::iterator in;
			lo=repay_principal.begin();
			in=repay_intereset.begin();
			lo=repay_principal.erase(lo);
			in=repay_intereset.erase(in);
		}
	};
	void Inv_depreciation()
	{
		if(depreciation.size()>0)
		{
			vector <int> ::iterator de;
			de=depreciation.begin();
			de=depreciation.erase(de);
		}
	}



};







#endif
