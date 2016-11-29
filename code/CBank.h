//CBank.h
#ifndef INC_CBANK
#define INC_CBANK
#include<stdio.h>
#include<math.h>
#include<vector>
#include"CCS_data.h"
#include"CEquipment.h"
#include "CFunction.h"
#include"CAgent.h"
#include"CConsumer.h"
#include"CProducer.h"

using namespace std;
class CBank :public CAgent
{
	FILE *bank_data;
	long long capital;//�������z
	int save;//�a���z
	int p_loan;//���Y�҂ւ̑ݏo�����z
	int p_amount;//
	int sum_loan;//�ݏo�����z
	int sum_interest;//�x���������v
	int amount;
	int huryou;
	int debt;//���H
	int reserve;
	int sum_a_save;//consumer�̗a���z�̑��v
	int sum_p_inte;
	int mo_sum;//����җa�����o���z
	int ou_sum;//����җa���a�����z
	int loan;
	double reserve_rate;//��������
	double r;//����
	double r0;//(1+r)��n��
	int n;//�ԍϊ���
	int koteihi;
	CCS_data *cd;
	CFunction *cf;
/////////////////////////////////////
	vector <CConsumer*> mem_con;
	vector <CWholesaler *> mem_whole;
	vector <CRetailer *> mem_retailer;
	vector <CEquipment *> mem_equip;
/////////////////////////////////////
	vector <CCS_data *> mem_cons;//consumer��CCS_data�W��
	vector <CCS_data *> mem_prod;//producer��CCS_data�W��
public:
	void Set_IC(long long bank_capital);//,int repay_period,double bank_increase_rate,double r_rate);
	
	void Set_parameter();
	void Create_csdata_c(int ag_n,int con_n);
	void Create_csdata_p(int ag_n,int pro_n);
	void Set_bd(FILE *bd){bank_data=bd;};
	void Show_bank(vector <CConsumer *> mem_con);
	void In_capital(int x){capital+=x;};
	long long Get_capital(){return capital;};
	void Erease_account(int pro_n);
	int banker(int pro_n);
	void banker_l(vector <CRetailer *> mem_retailer,int pro_n);
	int Get_debt(){return debt;};
	int Repayment_lack(int pro_no,int amount);
	void suply_inte_aft(){sum_interest=sum_interest-sum_p_inte;};
	int Get_inte(int pro_no);
	int Get_hensai(){return n;};

	void Set_koteihi(int ko){koteihi=ko;};
	int Get_koteihi(){return koteihi;};
//////////////////////////////////////////////�|�Y����
	void renew_stock_price_banker(vector <CProduct *> mem_product,int banker_no);
//////////////////////////////////////////////������
//	void Set_reserve(int save1){reserve=save1;	save=reserve;}
	void Set_reserve(int x){reserve=x;};
	int Get_reserve(){return reserve;};
	int loan_check(int loan);
	double Get_reserve_rate(){return reserve_rate;};
////////////////////////////////////////��s�a������
	template<class T>int suply_inte(T & member,int con_no);
	int suply_inte_c(vector <CConsumer *> mem_con,int con_no,int cap);
	int suply_inte_r(vector <CRetailer *> mem_retailer,int pro_no,int cap);
	int suply_inte_w(vector <CWholesaler *> mem_whole,int pro_no,int cap);
	int suply_inte_e(vector <CEquipment *> mem_equip,int pro_no,int cap);
//////////////////////////////////////////�����ؓ���
	int Loan_l_r(vector <CRetailer *> mem_retailer,int pro_no,int loan,int hensai_t);
	int Loan_l_w(vector <CWholesaler *> mem_whole,int pro_no,int loan,int hensai_t);
	int Get_inte_r(vector <CRetailer *> mem_retailer,int pro_no);
	int Get_inte_w(vector <CWholesaler *> mem_whole,int pro_no);

	template<class T> int Get_inte(T &member, int pro_no);
////////////////////////////////////////�����ؓ��ԍ�

	template<class T> void Repayment(T &member,int pro_no);
	template<class T> int Get_repayment_data(T &member,int pro_no);

	void Repayment_r(vector <CRetailer *> mem_retailer,int pro_no);
	void Repayment_w(vector <CWholesaler *> mem_whole,int pro_no);
	int Get_repayment_data_r(vector <CRetailer *> mem_retailer,int pro_no);
	int Get_repayment_data_w(vector <CWholesaler *> mem_whole,int pro_no);
////////////////////////////////////////Employ�p�֐�
	void Set_employ(int no){mem_employ.push_back(no);};
	void Set_employ_const_wage(int no){mem_employ_const_wage.push_back(no);};
	int Get_no_employ(){return mem_employ.size();};
	int Get_employer(int no){return mem_employ[no];};
	int Get_employ_const_wage(int no){return mem_employ_const_wage[no];};
	void Erase_employ_const_wage(int no);
///////////////////////////////////////Shiwake�p�֐�
	void Set_shiwake_loan_long(int i_period,int loan_l);
	void Set_shiwake_loan(int i_period,int loan);
	void Set_shiwake_yokin_azuke(int i_period,int capital);
	void Set_shiwake_yokin_hikidashi(int i_period,int depo_m);
	void Set_shiwake_risoku(int i_period,int interest);
	void Set_shiwake_loan_hensai(int i_period,int loan,int loan_r);
	void Set_shiwake_loan_l_hensai(int i_period,int loan_l,int loan_lr);
	void Set_shiwake_kisyu(int i_period,int mibarai,int pay_b);
	void Set_shiwake_kyuyo(int i_period,int mibarai);
	void Set_shiwake_shihon(int i_period,long long genkin,long long yokin);
	void Set_shiwake_tousan(int i_period,int loan_l,int loan);
	void Set_shiwake_pay_bonus(int i_period,int ammount);
	void Set_bonus_account_clac(){bonus=cac.Get_kimatu_mibarai_bonus()/Get_no_employ();};
///////////////////////////////////////////////////

	//��������ݔ��������p�֐��Q
	int Inv_loan_confirm();		//�ݏo�\���̕ԓ�
	template <class T>int Inv_Loan_l(T &ce,int loan,int hensai_t);			//�ݏo�����A���YEquip�̎Q�Ƃ�����
	void Inv_repayment(int amount,int inte);		//�ԍϏ����A���f�[�^�ƈقȂ��Ƃ̎Q�Ƃ͎��������ȓ��̏����̂ݍs��


};
void CBank::Inv_repayment(int amount,int inte)
{
	capital+=amount;							
	sum_interest+=inte;
	amount+=amount;
	sum_loan=sum_loan-(amount-inte);
	p_amount+=amount-inte;

}

int CBank::Inv_loan_confirm()
{
	//�ؓ��f���A�\�Ȃ�1�A�s�\�Ȃ�0��Ԃ�

	int out=1;		//���݁A�����ɂ͎؂����̉ۂ𔻒f���Ă��Ȃ��̂Ŗ������ݏo
	return out;

}
template <class T>int CBank::Inv_Loan_l(T &ce,int loan,int hensai_t)
{
	//�����ؓ����A�����x���z�v�Z
	int i;
	int size,out;
	int risoku,hensai;
	int loan_zan;
	size=mem_retailer.size();
	out=loan;
	
	for(i=0;i<hensai_t;i++)
	{
		if(i==0)
		{
			risoku=int(loan*r);
			hensai=int((risoku*r0)/(r0-1));
			loan_zan=loan-(hensai-risoku);
		}
		else if(i==hensai_t-1)
		{
			risoku=int(loan_zan*r);
			hensai=loan_zan+risoku;
			loan_zan=loan_zan-(hensai-risoku);
		}
		else
		{
			risoku=int(loan_zan*r);
			loan_zan=loan_zan-(hensai-risoku);
		}
		
		ce->Set_repay_principal(hensai-risoku);
		ce->Set_repay_interest(risoku);
		ce->Set_depreciation(hensai-risoku);
		
	}
	return out;

}

void CBank::Set_parameter()
{
	sum_loan=0;//��s�̑ݏo�����z
	amount=0;
	save=0;
	reserve_rate=cpara->GET_PARA_reserve_rate();
	sum_interest=0;
	mo_sum=0;
	ou_sum=0;
	p_loan=0;
	p_amount=0;
	r=cpara->GET_PARA_bank_increase_rate()/12;//������
	n=cpara->GET_PARA_repay_period();//�ԍϊ���
	r0=pow((1+r),n);//(1+r)��n��

	//FILE�ݒ�
	bank_data=cpara->FI_Get_bank_data();


}
void CBank::Set_shiwake_loan_long(int i_period,int loan_l)
{
	cac.Set_shiwake(i_period,loan_l,"�����ݏo��","�����ݏo","�a��",loan_l,0,2);
}
void CBank::Set_shiwake_yokin_azuke(int i_period,int capital)
{
	cac.Set_shiwake(i_period,capital,"����","�a���a��","�a��",capital,0,2);
}
void CBank::Set_shiwake_pay_bonus(int i_period,int amount)
{
	cac.Set_shiwake(i_period,0,"�{�[�i�X","�ŋ��x��","����",amount,1,0);
	cac.Set_shiharai_bonus(amount);
}
void CBank::Set_shiwake_loan(int i_period,int loan)
{
	cac.Set_shiwake(i_period,loan,"�Z���ݏo��","�Z���ݏo","�a��",loan,0,2);
}
void CBank::Set_shiwake_yokin_hikidashi(int i_period,int depo_m)
{
	cac.Set_shiwake(i_period,depo_m,"�a��","�a�����o","����",depo_m,2,0);
}
void CBank::Set_shiwake_risoku(int i_period,int interest)
{
	cac.Set_shiwake(i_period,interest,"�x������","�x��������","�a��",interest,1,2);
}
void CBank::Set_shiwake_loan_hensai(int i_period,int loan,int loan_r)
{

	cac.Set_shiwake(i_period,loan,"�a��","�Z���ݏo�ԍ�","�Z���ݏo��",loan,2,0);
	cac.Set_shiwake(i_period,loan_r,"�a��","�Z���ݏo����","��旘��",loan_r,2,3);
	
}
void CBank::Set_shiwake_loan_l_hensai(int i_period,int loan_l,int loan_lr)
{
	cac.Set_shiwake(i_period,loan_l,"�a��","�����ݏo�ԍ�","�����ݏo��",loan_l,2,0);
	cac.Set_shiwake(i_period,loan_lr,"�a��","�����ݏo����","��旘��",loan_lr,2,3);
	fprintf(cpara->FI_Get_bank_data(),"%d , %d\n",loan_l,loan_lr);
}
void CBank::Set_shiwake_kisyu(int i_period,int mibarai,int pay_b)
{
	cac.Set_shiwake(i_period,mibarai,"����","���񏈗�","������p",mibarai,1,2);
	cac.Set_shiwake(i_period,mibarai,"��ʊǗ���","���񏈗�","����",mibarai,1,1);
}
void CBank::Set_shiwake_kyuyo(int i_period,int mibarai)
{
	cac.Set_shiwake(i_period,mibarai,"������p","���^�x��","����",mibarai,2,0);
}
void CBank::Set_shiwake_shihon(int i_period,long long genkin,long long yokin)
{
	cac.Set_shiwake_T(i_period,genkin,"����","�����ێ���","���厑�{",genkin,0,2);
}
void CBank::Set_shiwake_tousan(int i_period,int loan_l,int loan)
{
	cac.Set_shiwake(i_period,loan_l,"���ʑ���","�|�Y����","�����ݏo��",loan_l,1,0);
	cac.Set_shiwake(i_period,loan,"���ʑ���","�|�Y����","�Z���ݏo��",loan,1,0);
}
void CBank::Erase_employ_const_wage(int no)
{
	vector <int> ::iterator del_e=mem_employ_const_wage.begin();
	del_e=mem_employ_const_wage.erase(del_e+no);
}

void CBank::Set_IC(long long bank_capital)
{
	capital=bank_capital;
}
int CBank::loan_check(int loan)
{
	int out;
	if(long long((Get_genkin_suitoutyou_zandaka_l()/3*2)-Get_loan_s_zandaka()-Get_loan_l_zandaka()-reserve)>0){
		out=loan;
	}else{
		out=0;	printf("out0\n");
	}
	return out;
}
template<class T> int CBank::Get_inte(T &member, int pro_no)
{
	int i,size,out=0,size_l;
	size=member.size();
	for(i=0;i<size;i++)
	{
		if(member[i]->Get_Producer_no()==pro_no)
		{
			size_l=member[i]->Get_loan_data();
			if(size_l>0)
			{
				out=member[i]->Get_inte();
			}
		}
	}
	return out;
}
int CBank::Get_inte_r(vector <CRetailer *> mem_retailer,int pro_no)
{
	int i,size,out=0,size_l;
	size=mem_retailer.size();
	for(i=0;i<size;i++)
	{
		if(mem_retailer[i]->Get_Producer_no()==pro_no)
		{
			size_l=mem_retailer[i]->Get_loan_data();
			if(size_l>0)
			{
				out=mem_retailer[i]->Get_inte();
			}
		}
	}
	return out;
}
int CBank::Get_inte_w(vector <CWholesaler *> mem_whole,int pro_no)
{
	int i,size,out=0,size_l;
	size=mem_whole.size();
	for(i=0;i<size;i++)
	{
		if(mem_whole[i]->Get_Producer_no()==pro_no)
		{
			size_l=mem_whole[i]->Get_loan_data();
			if(size_l>0)
			{
				out=mem_whole[i]->Get_inte();
			}
		}
	}
	return out;
}

template<class T> int CBank::suply_inte(T &member,int con_no)
{

	int i,out=0,si,cap;
	double rate,cm;
	si=sum_interest;
	cap=Get_yokin_suitoutyou_zandaka();


	if(cf->Comp_AGEvec_VAR(member,con_no)==1)
	{
		i=cf->Comp_AGEvec_VAR_return_no(member,con_no);
		cm=member[i]->Get_yokin_suitoutyou_zandaka();//�a���z�����o��
		rate=double(cm/cap);//�eAgent�̗a���z�̊���
		rate=0.005/12;
		out=int(cm*rate);
		ou_sum+=out;
		save+=out;
		sum_p_inte+=out;
	}
	return out;
}

int CBank::suply_inte_c(vector <CConsumer *> mem_con,int con_no,int cap)
{
	int i,size,out=0,si;
	double rate,cm;
	si=sum_interest;
	size=mem_con.size();
	for(i=0;i<size;i++)
	{
		if(mem_con[i]->Get_Consumer_no()==con_no)
		{
//20110224			cm=mem_con[i]->Get_yokin_zandaka();//�a���z�����o��
			cm=mem_con[i]->Get_yokin_suitoutyou_zandaka();//�a���z�����o��
			rate=double(cm/cap);//�eAgent�̗a���z�̊���
			rate=0.005/12;
			out=int(cm*rate);
			ou_sum+=out;
			save+=out;
			sum_p_inte+=out;
		}
	}
	return out;
}
int CBank::suply_inte_r(vector <CRetailer *> mem_retailer,int pro_no,int cap)
{
	int i,size,out=0,si;
	double rate,cm;
	si=sum_interest;
	size=mem_retailer.size();
	for(i=0;i<size;i++)
	{
		if(mem_retailer[i]->Get_Producer_no()==pro_no)
		{
//20110224			cm=mem_retailer[i]->Get_yokin_zandaka();//�a���z�����o��
			cm=mem_retailer[i]->Get_yokin_suitoutyou_zandaka();//�a���z�����o��
			rate=double(cm/cap);//�eAgent�̗a���z�̊���
			rate=0.005/12;
			out=int(cm*rate);
			ou_sum+=out;
			save+=out;
			sum_p_inte+=out;
		}
	}
	return out;
}
int CBank::suply_inte_w(vector <CWholesaler *> mem_whole,int pro_no,int cap)
{
	int i,size,out=0,si;
	double rate,cm;
	si=sum_interest;
	size=mem_whole.size();
	for(i=0;i<size;i++)
	{
		if(mem_whole[i]->Get_Producer_no()==pro_no)
		{
//20110224			cm=mem_whole[i]->Get_yokin_zandaka();//�a���z�����o��
			cm=mem_whole[i]->Get_yokin_suitoutyou_zandaka();//�a���z�����o��
			rate=double(cm/cap);//�eAgent�̗a���z�̊���
			rate=0.005/12;
			out=int(cm*rate);
			ou_sum+=out;
			save+=out;
			sum_p_inte+=out;
		}
	}
	return out;
}
int CBank::suply_inte_e(vector <CEquipment *> mem_equip,int pro_no,int cap)
{
	int i,size,out=0,si;
	double rate,cm;
	si=sum_interest;
	size=mem_equip.size();
	for(i=0;i<size;i++)
	{
		if(mem_equip[i]->Get_Producer_no()==pro_no)
		{
//20110224			cm=mem_equip[i]->Get_yokin_zandaka();//�a���z�����o��
			cm=mem_equip[i]->Get_yokin_suitoutyou_zandaka();//�a���z�����o��
			rate=double(cm/cap);//�eAgent�̗a���z�̊���
			rate=0.005/12;
			out=int(cm*rate);
			ou_sum+=out;
			save+=out;
			sum_p_inte+=out;
		}
	}
	return out;
}
int CBank::Loan_l_r(vector <CRetailer *> mem_retailer,int pro_no,int loan,int hensai_t)
{
	//�����ؓ����A�����x���z�v�Z
	int i,j;
	int size,out;
	int risoku,hensai;
	int loan_zan;
	size=mem_retailer.size();
	out=loan;
	
	for(i=0;i<hensai_t;i++)
	{
		if(i==0)
		{
			risoku=int(loan*r);
			hensai=int((risoku*r0)/(r0-1));
			loan_zan=loan-(hensai-risoku);
		}
		else if(i==hensai_t-1)
		{
			risoku=int(loan_zan*r);
			hensai=loan_zan+risoku;
			loan_zan=loan_zan-(hensai-risoku);
		}
		else
		{
			risoku=int(loan_zan*r);
			loan_zan=loan_zan-(hensai-risoku);
		}
		for(j=0;j<size;j++)
		{
			if(mem_retailer[j]->Get_Producer_no()==pro_no)
			{
				mem_retailer[j]->Set_loan_re(hensai-risoku,risoku);	
			}
		}
	}
	return out;
}
int CBank::Loan_l_w(vector <CWholesaler *> mem_whole,int pro_no,int loan,int hensai_t)
{
	//�����ؓ����A�����x���z�v�Z
	int i,j;
	int size,out;
	int risoku,hensai;
	int loan_zan;
	size=mem_whole.size();
	out=loan;
	for(i=0;i<hensai_t;i++)
	{
		if(i==0)
		{
			risoku=int(loan*r);
			hensai=int((risoku*r0)/(r0-1));
			loan_zan=loan-(hensai-risoku);
		}
		else if(i==hensai_t-1)
		{
			risoku=int(loan_zan*r);
			hensai=loan_zan+risoku;
			loan_zan=loan_zan-(hensai-risoku);
		}
		else
		{
			risoku=int(loan_zan*r);
			loan_zan=loan_zan-(hensai-risoku);
		}
		for(j=0;j<size;j++)
		{
			if(mem_whole[j]->Get_Producer_no()==pro_no)
			{
				mem_whole[j]->Set_loan_re(hensai-risoku,risoku);	
			}
		}
	}
	return out;
}
template<class T> void CBank::Repayment(T &member, int pro_no)
{
	int i;
	int am,inte,size_l;
	for(i=0;i<int(member.size());i++)
	{
		if(member[i]->Get_Producer_no()==pro_no)
		{
			size_l=member[i]->Get_loan_data();
			if(size_l>0)
			{
				am=member[i]->Get_loan_amount();
				inte=member[i]->Get_inte();
				capital+=am;
				sum_interest+=inte;
				amount+=am;
				sum_loan=sum_loan-(am-inte);
				p_amount+=am-inte;
				member[i]->Repayment();
			}
		}
	}
}
void CBank::Repayment_r(vector <CRetailer *> mem_retailer,int pro_no)
{
	int i;
	int size,am,inte,size_l;
	size=mem_retailer.size();
	for(i=0;i<size;i++)
	{
		if(mem_retailer[i]->Get_Producer_no()==pro_no)
		{
			size_l=mem_retailer[i]->Get_loan_data();
			if(size_l>0)
			{
				am=mem_retailer[i]->Get_loan_amount();
				inte=mem_retailer[i]->Get_inte();
				capital+=am;
				sum_interest+=inte;
				amount+=am;
				sum_loan=sum_loan-(am-inte);
				p_amount+=am-inte;
				mem_retailer[i]->Repayment();
			}
		}
	}
}
void CBank::Repayment_w(vector <CWholesaler *> mem_whole,int pro_no)
{
	int i;
	int size,am,inte,size_l=0;
	size=mem_whole.size();
	for(i=0;i<size;i++)
	{
		if(mem_whole[i]->Get_Producer_no()==pro_no)
		{
			size_l=mem_whole[i]->Get_loan_data();
			if(size_l>0)
			{
				am=mem_whole[i]->Get_loan_amount();
				inte=mem_whole[i]->Get_inte();
				capital+=am;
				sum_interest+=inte;
				amount+=am;
				sum_loan=sum_loan-(am-inte);
				p_amount+=am-inte;
				mem_whole[i]->Repayment();
			}
		}
	}
}
template<class T> int CBank::Get_repayment_data(T &member, int pro_no)
{
	int i;
	int size_l=0;
	int amount=0;
	for(i=0;i<int(member.size());i++)
	{
		if(member[i]->Get_Producer_no()==pro_no)
		{
			size_l=member[i]->Get_loan_data();//return loan.size();//�c��ԍϊ���
			if(size_l>0)
			{
				amount=member[i]->Get_loan_amount();//return loan[0];
			}
		}
	}
	return amount;
}
int CBank::Get_repayment_data_r(vector <CRetailer *> mem_retailer,int pro_no)
{
	int i;
	int size;
	int size_l=0;
	int amount=0;
	size=mem_retailer.size();
	for(i=0;i<size;i++)
	{
		if(mem_retailer[i]->Get_Producer_no()==pro_no)
		{
			size_l=mem_retailer[i]->Get_loan_data();//return loan.size();//�c��ԍϊ���
			if(size_l>0)
			{
				amount+=mem_retailer[i]->Get_loan_amount();//return loan[0];
			}
		}
	}
	return amount;
}
int CBank::Get_repayment_data_w(vector <CWholesaler *> mem_whole,int pro_no)
{
	int i;
	int size;
	int size_l=0;
	int amount=0;
	size=mem_whole.size();
	for(i=0;i<size;i++)
	{
		if(mem_whole[i]->Get_Producer_no()==pro_no)
		{
			size_l=mem_whole[i]->Get_loan_data();//return loan.size();//�c��ԍϊ���
			if(size_l>0)
			{
				amount+=mem_whole[i]->Get_loan_amount();//return loan[0];
			}
		}
	}
	return amount;
}


void CBank::renew_stock_price_banker(vector<CProduct *>mem_product , int banker_no)
{
	int i;
	int size;
	int price;
	size=mem_product.size();
	for(i=0;i<size;i++)
	{
		if(mem_product[i]->Get_Producer_no()==banker_no)
		{
			price=mem_product[i]->Get_price();
			mem_product[i]->Set_Producer_no(Get_Agent_no());
			mem_product[i]->Set_price(price/2);
		}
	}
}


#endif