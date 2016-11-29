//CEquipment.h
#ifndef INC_EQUIPMENT
#define INC_EQUIPMENT
#include <stdio.h> 
#include <vector>
using namespace std;

class CEquipment :public CProducer
{

	int comp_q;//�������̂��̒l�i�ݔ�������̂��̐��i��ʂ̍ő吶�Y�ʁj
	int pro_price;//�v���W�F�N�g�p�̉��i(�����ɕK�v�ȋ��z�j

public:
	void Estimate(int c_q,double capa_increase_rate,int invest_money);
	void Labor_Estimate(int invest_money);
	int Get_comp_q(){return comp_q;};
	int Get_project_price(){return pro_price;};
	void Set_shiwake_uriage(int i_period,int pro_price,int genka);
	void Set_shiwake_yokin_hikidashi(int i_period,int depo_m);
	void Set_shiwake_kyuyo(int i_period,int new_income);
	void Set_shiwake_loan(int i_period,int loan);
	void Set_shiwake_yokin_azuke(int i_period,int b_m);
	void Set_shiwake_seisan(int i_period,int genka);
	void Set_shiwake_loan_long(int i_period,int loan_l);
	void Set_shiwake_konyu(int i_period,int price_w);
	void Set_shiwake_shihon(int i_period,int genkin,int yokin);
	void Set_shiwake_kisyu(int i_period,int mibarai,int pay_b);
	void Set_shiwake_loan_s_hensai(int i_period,int loan,int loan_r);
	void Set_shiwake_kimatu(int i_period,int azuke_r);
	void Set_shiwake_Labor_uriage(int i_period,int pro_price);		//�ݔ��̐��Y�Ɣ̔��ɂ����錴�������ɂ���ĈႤ�̂�
	void Set_shiwake_Labor_hanbai(int i_period,int genka);			//���̓��ނ𕪊�����

};
void CEquipment::Set_shiwake_Labor_hanbai(int i_period,int genka)
{
	cac.Set_shiwake(i_period,genka,"���㌴��","���i�̔�","�ݔ�",genka,1,0);
}

void CEquipment::Set_shiwake_Labor_uriage(int i_period,int genka)
{
	cac.Set_shiwake(i_period,pro_price,"����","���i�̔�","����z",pro_price,0,3);
}
void CEquipment::Set_shiwake_uriage(int i_period,int pro_price,int genka)
{
	cac.Set_shiwake(i_period,genka,"���㌴��","���i�̔�","�ݔ�",genka,1,0);
	cac.Set_shiwake(i_period,pro_price,"����","���i�̔�","����z",pro_price,0,3);
}
void CEquipment::Set_shiwake_yokin_hikidashi(int i_period,int depo_m)
{
	cac.Set_shiwake(i_period,depo_m,"����","�a�����o","�a��",depo_m,0,0);
}
void CEquipment::Set_shiwake_loan(int i_period,int loan)
{
	cac.Set_shiwake(i_period,loan,"�a��","�Z���ؓ�","�Z���ؓ���",loan,0,2);
}
void CEquipment::Set_shiwake_kyuyo(int i_period,int new_income)
{
	cac.Set_shiwake(i_period,new_income,"������p","���^�x��","����",new_income,2,0);
}
void CEquipment::Set_shiwake_yokin_azuke(int i_period,int b_m)
{
	cac.Set_shiwake(i_period,b_m,"�a��","�a������","����",b_m,0,0);
}
void CEquipment::Set_shiwake_loan_long(int i_period,int loan_l)
{
	cac.Set_shiwake(i_period,loan_l,"����","�����ؓ�","�����ؓ���",loan_l,0,2);
}
void CEquipment::Set_shiwake_seisan(int i_period,int genka)
{
	cac.Set_shiwake(i_period,genka,"���㌴��","�ݔ����Y","�J����",genka,1,1);
	cac.Set_shiwake(i_period,genka,"�ݔ�","�ݔ����Y","���㌴��",genka,0,1);
}
void CEquipment::Set_shiwake_shihon(int i_period,int genkin,int yokin)
{
	cac.Set_shiwake(i_period,genkin,"����","�����ێ���","���厑�{",genkin,0,2);
	cac.Set_shiwake(i_period,yokin,"�a��","�����ێ���","���厑�{",yokin,0,2);
}
void CEquipment::Set_shiwake_kisyu(int i_period,int mibarai,int pay_b)
{
	cac.Set_shiwake(i_period,mibarai,"����","���񏈗�","������p",mibarai,1,2);
	cac.Set_shiwake(i_period,mibarai,"�J����","���񏈗�","����",mibarai,1,1);
}
void CEquipment::Set_shiwake_loan_s_hensai(int i_period,int loan,int loan_r)
{
	cac.Set_shiwake(i_period,loan,"�Z���ؓ���","��������","�a��",loan,2,0);
	cac.Set_shiwake(i_period,loan_r,"�Z���ؓ�����","��������","�a��",loan_r,1,0);
}
void CEquipment::Set_shiwake_kimatu(int i_period,int azuke_r)
{
	cac.Set_shiwake(i_period,azuke_r,"�a��","��������","��旘��",azuke_r,0,3);
}
void CEquipment::Estimate(int c_q,double capa_increase_rate,int invest_money)
{
	comp_q=int(c_q*capa_increase_rate);//printf("comp_q=%d\n",comp_q);
		//c_q:�����O�̂��̐��i��ʂ̍ő吶�Y��
	pro_price=invest_money;
}
void CEquipment::Labor_Estimate(int invest_money)
{
	pro_price=invest_money;
}







#endif