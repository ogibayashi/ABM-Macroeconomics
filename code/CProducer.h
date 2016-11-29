//CProducer.h
#ifndef INC_CPRODUCER
#define INC_CPRODUCER
#include <stdio.h> 
#include "CRandum.h"
#include "CProduct_class.h"
#include "CProduct.h"
#include "CJob_info.h"
#include "CEquip.h"
#include <vector>
using namespace std;

class CProducer :public CAgent
{
	int Producer_no;//���̐��i�𐶎Y�����G�[�W�F���g�̔ԍ�
	int Producer_type;
	int n_class;//���Y���鐻�i��ʂ̐�
	int *class_no;
	int rieki;
	int material;
	int cost;
	int capital;			//����W�v��̏��L�z
	int fixed_costs;		//�Œ��(�l����j
	int nop_sum;			//Number of production���Y��
	double adj_sens;		//Adjustment Sensitivity  �������x
	int q_sa;				//���S�݌ɒl
	int eqw;				//�ݔ������v���t���O�P�Ȃ�v��
	int eq_data;			//�ݔ����Y
	int equip_end;			//�ݔ��ϋv
	int loan_time;			//�Z���ؓ��A��������
	int loan_time_limit;	//�Z���ؓ��A�������񐔏���@����l�ɒB�����ꍇ�ɉ���
	int dismiss_flag;		//���كt���O
	int dismiss_no;			//���َ҃i���o�[
	int min_genka_whole;		//�z�[���Z���[�p�����i�ŏ����i�j
	int new_worker_checker;	//�V�K�ٗp�Ҋm�F�`�F�b�J�[

	double CR_price_up_rate;
	double CR_price_down_rate;
	double CR_max_q_re;
	double CR_min_q_re;
	int yakuin_housyu;		//������V�z�i����ɑO���ň����㗘�v����Z�o�i��V�͂��̍ۂɊ�Ƒ��̉�v�������s���j
	int R_koubai_yosan;		//���e�C���[���i�w���z�i������V�z�����Ɍ���j

	int Labor_genryou;
	int Labor_bonus;
	int Labor_koteikyu;

	
	CEquip *ce;

	
protected:
	vector <int> new_worker_no;	//�V�K�ٗp�҃i���o�[
	double alpha;//���i=����*alpha�Ƃ���
	int koteihi;
	int hendouhi;
	int qmaxmax;	int qmaxmin;
	int e_flag;
	double pay_rate;
	int price_w;

	double min_price_p;	double max_price_p;	double min_price_m;	double max_price_m;
	double Adjustment_Sensitivity;
	double max_q_re;	double min_q_re;
	int max_ban;
	CProduct *cp;
	CProduct_class *pc;
	CJob_info *cji;			//���l���N���X�@�쐬����Market�̏W���ɓn��
	

	vector <CProduct_class *> mem_class_p;
	vector <CProduct *> mem_bought_p;
	vector <int> repay_loan_l;//�ؓ���̖����̃��[���ԍϊz�̏W��
	vector <int> repay_inte_l;//�ؓ���̖������̎x�������̏W��
public:
	void CR_set_price_q_rate()
	{
		CR_price_up_rate=cr->sdrand(cpara->GET_PARA_price_up_rate()/2,cpara->GET_PARA_price_up_rate());
		CR_price_down_rate=cr->sdrand(cpara->GET_PARA_price_down_rate()/2,cpara->GET_PARA_price_down_rate());
		CR_max_q_re=cr->sdrand(cpara->GET_PARA_max_q_re()/2,cpara->GET_PARA_max_q_re());
		CR_min_q_re=cr->sdrand(cpara->GET_PARA_min_q_re()/2,cpara->GET_PARA_min_q_re());
	};
	
	void Reset_new_worker(){new_worker_checker=0;new_worker_no.clear();};
	void Set_new_worker(int no){new_worker_checker=1;new_worker_no.push_back(no);};

	void Labor_reset_keihi(){Labor_bonus=0;Labor_koteikyu=0;Labor_genryou=0;}
	void Labor_set_bonus(int a){Labor_bonus=a;};
	void Labor_set_koteikyu(int a){Labor_koteikyu=a;};
	void Labor_set_genryou(int a){Labor_genryou=a;};
	int Labor_mibarai(){return Labor_bonus+Labor_koteikyu+Labor_genryou;}
	int Get_mibarai_housyu(){return cac.Get_mibarai_housyu();}
	
	
	int Get_new_worker_size(){return new_worker_no.size();};
	int Get_new_worker_no(int i){return new_worker_no[i];};
	int Get_new_worker_checker(){return new_worker_checker;};
	vector <int> Get_new_worker_vec(){return new_worker_no;};
	void New_set_price();
	int Get_mem_class_p_size();
	void Reset_loan_time(){loan_time=0;};

	void Set_IC();//�����ݒ肻�̑�
	void Define_revised_price(int ncr_p_i);//mem_class_p[ncr_p_i]�̉��艿�i�����肷��
	void Renew_stock_price(vector <CProduct *> mem_product);
	int Get_max_price(int ncr_p_i);//mem_class_p[ncr_p_i]��max_price�����o��
	int Get_min_price(int ncr_p_i);//mem_class_p[ncr_p_i]��min_price�����o��
	double Get_ave_price(int ncr_p_i);//mem_class_p[ncr_p_i]��ave_price�����o��
	int Get_nstock(int ncr_p_i);//mem_class_p[ncr_p_i]��nstock(����c�萔)�����o��
	int Get_price(int ncr_p_i);//mem_class_p[ncr_p_i]��price�����o��
	void Set_price(int ncr_p_i,int price1);//mem_class_p[ncr_p_i]��price��price1������
	void Def_stock(vector <CProduct *> mem_product);
	void Show_stock();
	void Def_price_statics(vector <CProduct_class *> mem_class_statics);
	void Show_price_statics();
	void CProducer::Def_stock_price_statics(vector <CProduct_class *> mem_class_stock_statics);
	void Set_qmaxmax(int qmaxmax1,int qmaxmin1,double min_q_init1);
	void Set_Producer_no(int Producer_no1){Producer_no=Producer_no1;};
	int Get_Producer_no(){return Producer_no;};
	void Set_Producer_type(int Producer_type1){Producer_type=Producer_type1;};
	int Get_Producer_type(){return Producer_type;};
	void Create_Product_class_p(int max_memo_time,int max_reac_flag);
	
	int Get_n_class(){return mem_class_p.size();};
	void Set_n_class(int n_class1);
	void Set_class_no_p();//���ׂĂ̐��i��ʂɎ�ʔԍ�������
	void Set_class_no_p(vector <int> mem_ncr_r);//mem_ncr_r�̐��i��ʂɎ�ʔԍ�������
	void CProducer::Set_class_no_p(vector <int> mem_ncr_r,vector <int> mem_ncr_r_m);
	int Get_class_no(int n){return mem_class_p[n]->Get_class_no();};
	virtual void Def_qmax();
	virtual void Def_koteihi(int min_koteihi,int max_koteihi);
	int Get_koteihi(){return koteihi;};
	virtual void Def_hendouhi(int min_hendouhi,int max_hendouhi);
	virtual void Seisan_plan(double price_k,int first_price);
	virtual void Seisan_plan_revised(double q_limit_k,double price_increase_rate,double max_q_re,double min_q_re,double Adjustment_Sensitivity);
	virtual void Seisan_plan_revised(vector <CProduct *> mem_product_whole,double max_q_re,double min_q_re,double Adjustment_Sensitivity);
	virtual void Seisan();
	virtual int Get_q(int i);//j�Ԗڐ��i��ʂ̐��i���Y�ʂ����o��
	virtual CProduct* Get_product_fi(int i,int j)
	{
		return mem_class_p[i]->Get_product(j);
	};
	virtual CProduct* Get_product(int i,int j)
	{
		return mem_class_p[i]->Get_product(j);//mem_seihin[i]�����o��
	};
	void Set_employ(int no){mem_employ.push_back(no);};
	void Set_employ_const_wage(int no){
		int sum=0,i;
		for(i=0;i<int(mem_employ_const_wage.size());i++)	sum+=mem_employ_const_wage[i];
		fprintf(cpara->FI_Get_employ_file(),"employ_ size %d , sum=%d , ",mem_employ_const_wage.size(),sum);
		mem_employ_const_wage.push_back(no);
		sum=0;
		for(i=0;i<int(mem_employ_const_wage.size());i++)	sum+=mem_employ_const_wage[i];
		fprintf(cpara->FI_Get_employ_file(),"employ_ size %d , sum=%d\n",mem_employ_const_wage.size(),sum);
	};
	int Get_employ_const_wage(int no){return mem_employ_const_wage[no];};
	int Get_no_employ(){return mem_employ.size();};
	int Get_employer(int no){return mem_employ[no];};


	void Set_rieki(int ri,int i);
	void Set_material_no(vector <int> mem_ncr_w);
	int Get_material_need(int x){ return mem_class_p[x]->Get_material_need();};
	int Get_material_no(int x){return mem_class_p[x]->Get_material_no();};
	void Calc_cost(double q_limit_k,double p_inc_rate,double min_p,double max_p,double min_m,double max_m);
	void Deliv_material(CProduct * cp);
	void Set_capital(){capital+=rieki;rieki=0;};
	void Set_capital(int x){capital=x;};
	int Get_capital(){return capital;};

	void Show_test();
	void Seisan_revised();
	int Get_nop_sum(){return nop_sum;};
	int Get_nop(int i);

	int Get_capital_test(){int x;x=capital;capital=0;return x;};
	void Seisan_plan_w(int min_price_w,int max_price_w);
	int Def_q(int i);

	int Def_q_remodeling(int i,double max_q_re,double min_q_re,double Adjustment_Sensitivity);
	void Clear_p_class();
	void Clear_p_class_w();
	void Def_flag_price(int ncr_p_i,double p_in_rate,double min_p,double max_p,double min_m,double max_m);
	int Get_cost();
	int Get_eqw();
	int Get_eqw_no();
	int Get_g_eqw_no();//���{�����p�̐ݔ��i���o�[�I��
	int Get_class_rieki(int c_n){return mem_class_p[c_n]->Get_price()*mem_class_p[c_n]->Get_buy();};
	int Get_class_buy(int c_n){return mem_class_p[c_n]->Get_buy();};
	int Get_class_q_limit(int c_n){return mem_class_p[c_n]->Get_q_limit();};
	void Set_q_limit(int x,int i,int k){mem_class_p[i]->Set_q_limit(x);mem_class_p[i]->Set_q_limit_d(x/k);};
	void Set_rieki(int x);
	void CProducer::Set_shiwake_seisan_k(int i_period,int p_gen);

	void bankr(int max_ban);
	void Set_koteihi(int ko){koteihi=ko;};
	int Get_rieki(){return rieki;};

	int Get_s_buy(){return price_w;};
	int Get_genka(int i){return mem_class_p[i]->Get_price_genka();};
	void Set_hendouhi(int x){hendouhi=x;};
	void Def_flag_price_w(int ncr_p_i,double price_increase_rate);
	void Decide_dismisses();
	int Get_dismiss_flag(){return dismiss_flag;};
	int Get_dismiss_no(){return dismiss_no;};
	void Set_loan_time_limit(int ltl){loan_time_limit=ltl;};
	void Set_bonus_account_clac(){bonus=cac.Get_kimatu_mibarai_bonus()/Get_no_employ();};

	void Set_material_need();
	virtual void Set_shiwake_seisan_k(int i_period,int p_gen,int pay_b);
	void Set_shiwake_hozyokin(int i_period,int hozyokin);
	int Get_equipment_revel(int x){return mem_class_p[x]->Get_equipment_revel();};
	void Set_init_equipment_revel(int x){mem_class_p[x]->Set_init_equipment_revel();};
	void Up_equipment_revel(int x){mem_class_p[x]->Up_equipment_revel();};
	void Adjust_q_init(int x);
	void Adjust_q(int x);
	int Get_hozyokin_out(){return cac.Get_hozyokin_out();};
	void First_set_q();

	void Set_cobb_k(int mem_class_no,double amount){mem_class_p[mem_class_no]->Set_cobb_k(amount);};
	double Get_cobb_k(int mem_class_no){return mem_class_p[mem_class_no]->Get_cobb_k();};
	void Set_shiwake_pay_bonus(int i_period,int ammount);

//////////////////////////////////
	int Get_loan_amount(){return repay_loan_l[0];}
	int Get_inte(){return repay_inte_l[0];}
	int Get_loan_data(){return repay_loan_l.size();};
	void Repayment();
	void Set_loan_re(int lo,int r_1);
	int Get_repay_loan_l_and_int();
//////////////////////////////////
	int Get_q_limit(int no){return mem_class_p[no]->Get_q_limit();};

	void CR_seisan();
	void CR_seisan_plan();
	void CR_set_koatari_genka();
	void CR_set_koatari_genryouhi(){for(int i=0;i<int(mem_class_p.size());i++)mem_class_p[i]->Set_koatari_genryouhi(mem_class_p[i]->CR_Get_koatari_genryouhi());};//calc_cost�������ς��Ȃ����߂ɉI�񂵂Đݒ�
	int CR_Get_koatari_genryouhi(int x){return mem_class_p[x]->Get_koatari_genryouhi();}; 
	int CR_Get_class_no_p(int x){return mem_class_p[x]->Get_class_no();};
	void CR_Seisan_plan_revised(vector <CProduct *>mem_product_whole,double max_q_re,double min_q_re,double Adjustment_Sensitivity);
	void CR_New_set_price();
	int CR_Def_q_remodeling(int i,double max_q_re,double min_q_re,double Adjustment_Sensitivity);

	void print_shihon(){if(Get_Agent_no()==8)fprintf(cpara->FI_Get_free_text2(),"%d\n",cac.Get_kamoku(2,"���厑�{"));};

	void Labor_out_put_data(){for(int i=0;i<int(mem_class_p.size());i++)mem_class_p[i]->Labor_output_data();};
	void Labor_limit_up_conf();
	void Labor_set_data();
	void Labor_set_unemployment_data(int new_salary)
	{
		//���l������
		int zyouyo=0;
		switch(cpara->Get_PARA_Labor_salary_change_switch())
		{
		case 0:

			for(int i=0;i<int(mem_class_p.size());i++)mem_class_p[i]->Labor_set_unemployment_data(new_salary);
			fprintf(cpara->FI_Get_Labor_writer(),"�Œ苋�^_�ϓ��Ȃ�_���[���N�����i�����͎��j\n");
			break;


		case 1:
			zyouyo=cac.Get_kimatu_riekizyouyo();
			if(zyouyo-new_salary*10>0)	new_salary=int(double(new_salary*cr->sdrand(1.1,1.3)));
			else if(zyouyo-new_salary*10<0)  new_salary=int(double(new_salary*cr->sdrand(0.9,0.7)));
			fprintf(cpara->FI_Get_Labor_writer(),"�Œ苋�^_�ϓ�_���[���N�����i�����͎��j\n");
			break;
		}
		for(int i=0;i<int(mem_class_p.size());i++)mem_class_p[i]->Labor_set_unemployment_data(new_salary);
	};
	void Labor_outside_data(int repay_time,int inv_price,double loan_rate)
	{
		//�O������
		for(int i=0;i<int(mem_class_p.size());i++)
		{
			mem_class_p[i]->Labor_set_repay_time(repay_time);
			mem_class_p[i]->Labor_set_invest_price(inv_price);
			mem_class_p[i]->Labor_set_loan_rate_period(loan_rate);
		}
	};
	void Labor_inside_data()
	{
		int total=0;
		for(int i=0;i<int(mem_employ.size());i++)	total+=mem_employ_const_wage[i];
		//��������
		for(int i=0;i<int(mem_class_p.size());i++)
		{
			mem_class_p[i]->Labor_set_worker_no(mem_employ.size());
			mem_class_p[i]->Labor_set_sum_fixed_salary(total);
			mem_class_p[i]->Labor_set_repayment_term(120);
			mem_class_p[i]->Labor_set_loan_state(Get_loan_data());
			mem_class_p[i]->Labor_set_genkin(cac.Get_yokin_suitoutyou_zandaka());

			fprintf(cpara->FI_Get_free_text2(),"genkin , %d , yokin %d\n",cac.Get_genkin_suitoutyou_zandaka(),cac.Get_yokin_suitoutyou_zandaka());
		
			mem_class_p[i]->Labor_set_inside_data();
			mem_class_p[i]->Labor_set_keihi(Labor_mibarai());
		}
	};


	void Labor_decision_limit_up_way();		//�g����@����
	void Labor_calc_employment_decision();	//�ٗp���v�v�Z
	void Labor_calc_investment_decision();	//�������v�v�Z
	void Labor_decision_limit_up();			//����
	template<class T> void Labor_Create_Jobs_info(T &mem_info);					//���l�[�o��
	void Labor_Set_Jobs_info();
	template<class T,class U,class V,class W>void Labor_reemploy(T& job_info,U& mem_con,V& mem_unemp,W& del_info,int &emp_num);


	void Labor_Reset_eqw(int product_class_no)
	{
		mem_class_p[product_class_no]->Reset_eqw();
	};

	struct Labor_limit_up_data 
	{
		int limit_up_decide;	//�����s���̗L���@0:�Ȃ��@1:����
		int product_class;		//���Y�i��W���̓Y�����ԍ��i�m�F�̎���mem_class_p�̓Y�����ԍ��j�@�@�@�@
		int way;				//�g����@�@�@�@�@0:�g�債�Ȃ��@1:�ٗp�@2:����
	} *L_lud;
	int Labor_get_limit_up_data_decide(){return L_lud->limit_up_decide;};
	int Labor_get_limit_up_data_productclass(){return L_lud->product_class;};
	int Labor_get_limit_up_data_way(){return L_lud->way;};

	void Labor_print_eqw();
	void Labor_test_dismiss_point(){loan_time=30;printf("%d\n",loan_time);};
	void Labor_test_up_point(){for(int i=0;i<int(mem_class_p.size());i++) mem_class_p[i]->Labor_test_up_point();};
	void Labor_Reset_limit_up_data();
	void Labor_decision_limit_up_way_not_emp();
	void Labor_calc_deicision();

	template<class T> void Labor_housyu(T & bank );
	void Calc_R_koubai_yosan(){						//���e�C���[���i�w���i�ቿ�i�Œ莑�{�j�w���\�Z���胋�[��
		switch(cpara->Get_PARA_Labor_R_buy_profit_switch())
		{
		case 0:
			if(cac.Get_touki_zyunsoneki()>0)	R_koubai_yosan=int(double((cac.Get_touki_zyunsoneki()-yakuin_housyu)*cpara->Get_PARA_R_koubai_yosan_rate()));
			else R_koubai_yosan=0;
			break;

		case 1:
			if(cac.Get_kisyu_riekizyouyo()>0)	R_koubai_yosan=int(double((cac.Get_kisyu_riekizyouyo()-yakuin_housyu)*cpara->Get_PARA_R_koubai_yosan_rate()));
			else R_koubai_yosan=0;
			break;

		case 2:
			if(cac.Get_yokin_suitoutyou_zandaka()-Labor_mibarai()>0) R_koubai_yosan=int(double(cac.Get_yokin_suitoutyou_zandaka()-Labor_mibarai())*double(cpara->Get_PARA_R_koubai_yosan_rate()));
			else R_koubai_yosan=0;
			break;

		}
		
	}
	int Get_R_koubai_yosan(){return R_koubai_yosan;};
	int Labor_Get_housyu(){return yakuin_housyu;};
	void Labor_recognition_riekiritu();


		//��������ݔ��������p�֐��Q
	void Inv_set_equipment_test(int class_no);				//�e�X�g�p
	void Inv_print_equipment_period(int class_no);			//�e�X�g�p

	
	void Inv_set_init_equipment_level(int class_no);		//�ݔ������ݒ�A�ݔ��𐶐����āAproduct_class�ɓ�����Aproduct_class�ɃJ�E���g�������āAequipment_level��ς���
	void Inv_Labor_inside_data();
	int Inv_get_loan_l_data();								//�ݔ������̕ԍϊ��ԃJ�E���g�A�����̕ԍς�����ꍇ�͍ő咷�̕���Ԃ�
	int Inv_get_loan_l_number();							//�ݔ������̕ԍϒ��̐�
	template <class T,class U> void Inv_investment(T &bank,U &equip,int &inv_no);	//�ݔ������s���A��s�Ɛݔ������������Ƃ��Ă��ׂĂ̍s���������ŏ��u
	int Inv_get_repayment_amount();								//Equip�̕ԍϊz�A������[0]�z���W�߂č��v���Ė߂�
	void Inv_repayment();			//�ԍύs���A��s�������ɂ��čs��
	
	int Inv_get_depreciation();
	int Inv_get_loan_l_amount();
	int Inv_get_loan_l_inte();
	void Inv_depreciation();

	void Set_shiwake_setubi(int i_period,int pro_price,int loan_l);
	void Inv_Labor_calc_deicision();

	void Set_shiwake_yokin_hikidashi(int i_period,int depo_m);

	void Print_sihon(){cac.print_test();};
	int Set_class_no_p(int count);

};
void CProducer::Set_shiwake_yokin_hikidashi(int i_period,int depo_m)
{
	cac.Set_shiwake(i_period,depo_m,"����","�a�����o","�a��",depo_m,0,0);
	
}

void CProducer::Inv_Labor_calc_deicision()
{
	int i;
	fprintf(cpara->FI_Get_Labor_writer(),"�ݔ��A�ٗp�\�z���v�v�Z\n");
	for(i=0;i<int(mem_class_p.size());i++)
	{
		if(mem_class_p[i]->Labor_Get_decision()==1)
		{
			mem_class_p[i]->Inv_Labor_calc_decision();	
		}
	}
}


void CProducer::Inv_depreciation()
{
	for(int i=0;i<int(mem_class_p.size());i++)
		mem_class_p[i]->Inv_depreciation();
}
int CProducer::Inv_get_depreciation()
{
	int i,sum=0;
	for(i=0;i<int(mem_class_p.size());i++)
	{
		sum+=mem_class_p[i]->Inv_get_depreciation();
	}
	return sum;
}
int CProducer::Inv_get_loan_l_amount()
{
	int i,amount=0;
	for(i=0;i<int(mem_class_p.size());i++)
	{
		amount+=mem_class_p[i]->Inv_get_loan_amount();
	}
	return amount;
}
int CProducer::Inv_get_loan_l_inte()
{
	int i,inte=0;
	for(i=0;i<int(mem_class_p.size());i++)
	{
		inte+=mem_class_p[i]->Inv_get_inte();
	}
	return inte;
}
void CProducer::Inv_repayment()
{
	for(int i=0;i<int(mem_class_p.size());i++)
	{
		mem_class_p[i]->Inv_repayment();
	}
}

int CProducer::Inv_get_repayment_amount()
{
	int i,sum=0;
	for(i=0;i<int(mem_class_p.size());i++)
	{
		sum+=mem_class_p[i]->Inv_get_loan_amount()+mem_class_p[i]->Inv_get_inte();
	}
	return sum;

}

void CProducer::Set_shiwake_setubi(int i_period,int pro_price,int loan_l)
{
	cac.Set_shiwake(i_period,loan_l,"�a��","�ݔ�����","�����ؓ���",loan_l,0,2);
	cac.Set_shiwake(i_period,loan_l,"����","�a�����o","�a��",loan_l,0,0);
	cac.Set_shiwake(i_period,pro_price,"�ݔ�","�ݔ�����","����",pro_price,0,0);
}
template <class T,class U> void CProducer::Inv_investment(T &bank,U &equip,int &inv_no)
{
	if(bank->Inv_loan_confirm()==1)
	{
		int c_n,pro_price=0,loan=0,loan_w=0,hensai_t=0;
		int zikoshikin=0;
		switch(cpara->Get_PARA_Labor_invest_capital_switch())
		{
		case 0:
			fprintf(cpara->FI_Get_Labor_writer(),"�ݔ��������v�v�Z_���Ȏ��{�g�p���Ȃ�\n");
			//�I�΂ꂽ�G�[�W�F���g���z�[���Z���[�̏ꍇ
			c_n=Labor_get_limit_up_data_productclass();//�����Ώۂ̐��i��ʔԍ���Ԃ�
			equip->Labor_Estimate(cpara->GET_PARA_invest_money());//������̍ő吶�Y��comp_q�Ɠ������zpro_price���`����
			pro_price=equip->Get_project_price();//�����ɕK�v�Ȃ����̊z
			loan_w=pro_price;//�ؓ����̊z

			ce=new CEquip;
			ce->Set_set_period(i_period);


			hensai_t=int(cr->seiki(cpara->GET_PARA_repay_time_ave(),cpara->GET_PARA_repay_time_bun()));//cb->Get_hensai()*kk+0.5);
			pro_price=int(pro_price);	
			loan_w=pro_price;//�ؓ����z

			loan=bank->Inv_Loan_l(ce,loan_w,hensai_t);

			if(loan>0)
			{
				Set_loan_l(loan);
				bank->Set_loan_l(loan);
				equip->Set_rieki(loan);
				mem_class_p[c_n]->Inv_set_equipment(ce);
				mem_class_p[c_n]->Inv_equipment_level_update();

				bank->Set_shiwake_loan_long(i_period,loan);
				bank->Set_shiwake_yokin_hikidashi(i_period,loan);
				Set_shiwake_setubi(i_period,pro_price,loan);
				equip->Set_shiwake_Labor_uriage(i_period,pro_price);
				equip->Set_shiwake_yokin_azuke(i_period,pro_price);
				bank->Set_shiwake_yokin_azuke(i_period,pro_price);		//�{���AEquip�̗a���U���̋�s����ƁA�A���A��s�P�Ŏd�����ŗa���҂̋�ʂ��s���Ă͂��Ȃ��̂ŉe���Ȃ�
				Labor_Reset_eqw(c_n);
				inv_no++;
			}	
			
			break;
		case 2:
			int zikoshikin=0;
			fprintf(cpara->FI_Get_Labor_writer(),"�ݔ��������v�v�Z_���Ȏ��{�g�p\n");

			c_n=Labor_get_limit_up_data_productclass();//�����Ώۂ̐��i��ʔԍ���Ԃ�
			equip->Labor_Estimate(cpara->GET_PARA_invest_money());//������̍ő吶�Y��comp_q�Ɠ������zpro_price���`����
			pro_price=equip->Get_project_price();//�����ɕK�v�Ȃ����̊z
			
			//�ݔ��̐���
			ce=new CEquip;
			ce->Set_set_period(i_period);


			zikoshikin=int(double(pro_price)*double(cpara->Get_PARA_owncash_rate_inv()));
			loan_w=pro_price-zikoshikin;//�ؓ����̊z
		
			fprintf(cpara->FI_Get_free_text(),"������:%d , ",Producer_no);
			if(Get_yokin_suitoutyou_zandaka()+Get_genkin_suitoutyou_zandaka()-zikoshikin>0)
			{
				hensai_t=int(cr->seiki(cpara->GET_PARA_repay_time_ave(),cpara->GET_PARA_repay_time_bun()));//cb->Get_hensai()*kk+0.5);
				pro_price=int(pro_price);	//loan_w=pro_price;//�ؓ����z
				loan=bank->Inv_Loan_l(ce,loan_w,hensai_t);
				fprintf(cpara->FI_Get_free_text(),"loan:%d , loan_w:%d\n",loan,loan_w);
			}


			if(loan>0)
			{
				Set_loan_l(loan);
				bank->Set_loan_l(loan);

				Set_shiwake_yokin_hikidashi(i_period,zikoshikin);
				bank->Set_shiwake_yokin_hikidashi(i_period,zikoshikin);
				

				equip->Set_rieki(loan+zikoshikin);
				mem_class_p[c_n]->Inv_set_equipment(ce);
				mem_class_p[c_n]->Inv_equipment_level_update();

				bank->Set_shiwake_loan_long(i_period,loan);
				bank->Set_shiwake_yokin_hikidashi(i_period,loan);
				Set_shiwake_setubi(i_period,pro_price,loan);
				equip->Set_shiwake_Labor_uriage(i_period,pro_price);
				equip->Set_shiwake_yokin_azuke(i_period,pro_price);

				bank->Set_shiwake_yokin_azuke(i_period,pro_price);		//�{���AEquip�̗a���U���̋�s����ƁA�A���A��s�P�Ŏd�����ŗa���҂̋�ʂ��s���Ă͂��Ȃ��̂ŉe���Ȃ�
				Labor_Reset_eqw(c_n);
				inv_no++;
				fprintf(cpara->FI_Get_Labor_writer(),"���Ȏ��{�����^�G�[�W�F���g�i���o�[�F%d , ���Ȏ��{�F%d , �ؓ��z�F%d\n",Get_Agent_no(),zikoshikin,loan);
			}


			break;
			
		}
	}
}

int CProducer::Inv_get_loan_l_data()
{
	int i,sum=0;
	for(i=0;i<int(mem_class_p.size());i++) sum+=mem_class_p[i]->Inv_get_loan_l_data();
	return sum;
}
int CProducer::Inv_get_loan_l_number()
{
	int i,sum=0;
	for(i=0;i<int(mem_class_p.size());i++) 
	{
			sum+=mem_class_p[i]->Inv_get_loan_l_number();
	}
	if(sum>cpara->GET_PARA_loan_time_limit()) 
	{
		printf("CProducer Inve_get_loan_l_number�ŃT�C�Y���K��ȏ�ɂȂ��Ă��܂�\n");
		scanf_s("%d",&i);
	}
	return sum;
}

void CProducer::Inv_Labor_inside_data()
	{
		int total=0;
		for(int i=0;i<int(mem_employ.size());i++)	total+=mem_employ_const_wage[i];
		//��������
		for(int i=0;i<int(mem_class_p.size());i++)
		{
			mem_class_p[i]->Labor_set_worker_no(mem_employ.size());
			mem_class_p[i]->Labor_set_sum_fixed_salary(total);
			mem_class_p[i]->Labor_set_repayment_term(120);

			mem_class_p[i]->Labor_set_loan_state(Inv_get_loan_l_data());
			mem_class_p[i]->Labor_set_loan_state_number(Inv_get_loan_l_number());


			mem_class_p[i]->Labor_set_genkin(cac.Get_yokin_suitoutyou_zandaka());

			fprintf(cpara->FI_Get_free_text2(),"genkin , %d , yokin %d\n",cac.Get_genkin_suitoutyou_zandaka(),cac.Get_yokin_suitoutyou_zandaka());
		
			mem_class_p[i]->Labor_set_inside_data();
			mem_class_p[i]->Labor_set_keihi(Labor_mibarai());
		}
	};

void CProducer::Inv_set_init_equipment_level(int class_no)
{
	ce=new CEquip;
	ce->Set_set_period(0);
	mem_class_p[class_no]->Inv_set_equipment(ce);
	mem_class_p[class_no]->Inv_equipment_level_update();
}

void CProducer::Inv_set_equipment_test(int class_no)
{
	ce=new CEquip;
	ce->Set_set_period(0);
	mem_class_p[class_no]->Inv_set_equipment(ce);
	mem_class_p[class_no]->Inv_equipment_level_update();
}
void CProducer::Inv_print_equipment_period(int class_no)
{
	for(int i=0;i<int(mem_class_p[class_no]->Inv_Get_mem_equip().size());i++)
		printf("producer_no %d , period %d\n",Agent_no,mem_class_p[class_no]->Inv_Get_mem_equip()[i]->Get_set_period());

}


void CProducer::Labor_recognition_riekiritu()
{
	int i,soneki=0,keihi=0;
	soneki=cac.Get_touki_zyunsoneki();
	keihi=int(cac.Get_touki_keihi_soukei());
	fprintf(cpara->FI_Get_Labor_keihi_soukei(),"%d , ",keihi);
	fprintf(cpara->FI_Get_Labor_keihi_toukisonekiritu(),"%.2lf , ",double(double(soneki)/double(keihi)));
	if(double(double(soneki)/double(keihi))>cpara->Get_PARA_Labor_riekiritu())
	{
		for(i=0;i<int(mem_class_p.size());i++)
		{
			mem_class_p[i]->Set_eqw(1);
		}
	}
}

template <class T>void CProducer::Labor_housyu(T& bank)
{

	yakuin_housyu=0;
	yakuin_housyu=cac.Get_mibarai_housyu();
	if(yakuin_housyu>0)
	{
		bank[Get_bank_no()]->Set_shiwake_yokin_hikidashi(i_period,yakuin_housyu);
		cac.Set_shiwake(i_period,yakuin_housyu,"����","�a�����o","�a��",yakuin_housyu,0,0);
		cac.Set_shiwake(i_period,0 ,"������V" ,"������V" , "����",yakuin_housyu,1,0);
		cac.Set_shiarai_housyu(yakuin_housyu);
	}

	fprintf(cpara->FI_Get_free_text2(),"%d_%d , ",Agent_no,yakuin_housyu);
	
}





void CProducer::Labor_decision_limit_up_way_not_emp()
{
	int i;
	fprintf(cpara->FI_Get_Labor_writer(),"�ݔ��A�ٗp�\�z���v�v�Z\n");
	for(i=0;i<int(mem_class_p.size());i++)
	{
		if(mem_class_p[i]->Labor_Get_decision()==1)
		{
			mem_class_p[i]->Inv_Labor_calc_decision();	
		}
	}
	

	int delta_rieki=0,cl_no=0;



	//��������̎菇
/*	�P�D���v�\���0
	�Q�D�����Ƃ����v������ꍇ�@���@���v���傫������I��
	�R�D�Е��̂ݗ��v������ꍇ�@���@���v������ꍇ��I���iA>0�AB<0�̎��AA�̔��肪��Ȃ��A>B�Ȃ̂�A�̂܂܁AB�̔��肪��Ȃ��B<A�Ȃ̂őI������A�Ɉڂ�j
	�S�D�������v���Ȃ����ꍇ�@�@���@���v��0�̂܂܁A�őI������way�������Ȃ���0�ɂȂ�̂œ������Ȃ����f
	�T�D���Ǝ҂����Ȃ��ꍇ�@�@�@���@���Ǝ҂Ȃ�=���v0�ɂȂ�

*/
	//��������X�g���N�`���̏�����
	delta_rieki=0;
	cl_no=9999;
	L_lud->limit_up_decide=0;
	L_lud->way=0;

	for(i=0;i<int(mem_class_p.size());i++)
	{
		if(delta_rieki<mem_class_p[i]->Labor_Get_delta_rieki_inv())
		{
			delta_rieki=mem_class_p[i]->Labor_Get_delta_rieki_inv();
			L_lud->limit_up_decide=1;
			L_lud->product_class=i;
			L_lud->way=2;
		}
	}

	if(L_lud->limit_up_decide==1)fprintf(cpara->FI_Get_Labor_writer(),"limit_up_decide:%d , class:%d , way:%d\n",L_lud->limit_up_decide,mem_class_p[L_lud->product_class]->Get_class_no(),L_lud->way);
}




void CProducer::Labor_Reset_limit_up_data()
{
	int i;
	L_lud->limit_up_decide=0;
	L_lud->product_class=9999;
	L_lud->way=0;

	for(i=0;i<int(mem_class_p.size());i++)
	{
		mem_class_p[i]->Labor_Reset_limit_up_data();
	}



}

void CProducer::Labor_print_eqw()
{
	int i;
	int eq_flag=0;
	fprintf(cpara->FI_Get_Labor_writer(),"producer_no=%d,",Get_Agent_no());
	for(i=0;i<ncr_p;i++)
	{
		fprintf(cpara->FI_Get_Labor_writer(),"classno:%d eqw:%d,",mem_class_p[i]->Get_class_no(),mem_class_p[i]->Get_eqw());
	}	
	fprintf(cpara->FI_Get_Labor_writer(),"\n");
}


template<class T,class U,class V,class W>void CProducer::Labor_reemploy(T& job_info,U& mem_con,V& mem_unemp,W& del_info,int &emp_num)
{
	int i,no,k=0;
	if(L_lud->way==1)
	{
	
		Reset_new_worker();
	
		printf("size=====%d\n",cji->Get_vote_number());
		if(cji->Get_vote_number()>0)
		{
			no=cji->Choice();
			printf("no=====%d\n",no);
			if(cf->Comp_AGEvec_VAR(mem_con,no)==1) 
			{
				fprintf(cpara->FI_Get_employ_file(),"memcon %d , con_no %d , k==%d\n",mem_con[k]->Get_Agent_no(),no,k);
				fprintf(cpara->FI_Get_Labor_writer(),"memcon %d , con_no %d , k==%d\n",mem_con[k]->Get_Agent_no(),no,k);
				k=cf->Comp_AGEvec_VAR_return_no(mem_con, no);

				fprintf(cpara->FI_Get_Labor_writer(),"agent_no %d , before %d ,k=%d, ",mem_con[k]->Get_Agent_no(),mem_con[k]->Get_office_no(),k);
				fprintf(cpara->FI_Get_employ_file(),"agent_no %d , before %d ,k=%d, ",mem_con[k]->Get_Agent_no(),mem_con[k]->Get_office_no(),k);
				Set_employ(mem_con[k]->Get_Agent_no());
				
				switch(cpara->Get_PARA_Labor_salary_change_switch())
				{
				case 0:
					Set_employ_const_wage(mem_con[k]->Get_constant_wage());
					fprintf(cpara->FI_Get_Labor_writer(),"�Œ苋�^_�ϓ��Ȃ�_���[���N�����i�ٗp���j\n");
					break;

				case 1:
					Set_employ_const_wage(mem_class_p[L_lud->limit_up_decide]->Labor_Get_new_fixed_salary());
					mem_con[k]->Set_constant_wage(mem_class_p[L_lud->limit_up_decide]->Labor_Get_new_fixed_salary());
					fprintf(cpara->FI_Get_Labor_writer(),"�Œ苋�^_�ϓ�_���[���N�����i�ٗp���j\n");
					break;
				}
				mem_con[k]->Set_office(Get_Producer_no());
				mem_con[k]->Set_office_type(Get_Agent_type());
				
				fprintf(cpara->FI_Get_employ_file()," after %d",mem_con[k]->Get_office_no());
				fprintf(cpara->FI_Get_employ_file(),"\n");

				fprintf(cpara->FI_Get_Labor_writer()," after %d",mem_con[k]->Get_office_no());
				fprintf(cpara->FI_Get_Labor_writer(),"\n");


				Labor_Reset_eqw(L_lud->product_class);
				//���ƎҏW������폜
				mem_unemp->Delete_unemployment(mem_con[k]->Get_Agent_no());
				emp_num++;

			}
		}

		
		printf("delete\n");
	

		//���l�[�W������폜

		del_info=job_info.begin();
		for(i=0;int(job_info.size());i++)
		{
			printf("size=%d , i=%d , info_no=%d , pro_no=%d\n",job_info.size(),i,job_info[i]->Get_producer_no(),Get_Agent_no());
			if(job_info[i]->Get_producer_no()==Get_Agent_no())
			{
				del_info=job_info.erase(del_info);
				break;
			}
			printf("end\n");
			del_info++;
		}
	
		cji->Reset_job_info();
	}
}

void CProducer::Labor_limit_up_conf()
{
	int i;
	fprintf(cpara->FI_Get_Labor_writer(),"producer_no=%d , labor_limit_up_conf\n",Get_Agent_no());
	fprintf(cpara->FI_Get_free_text2(),"�ݔ������t���O %d\n",cpara->GET_PARA_max_e_flag());
	for(i=0;i<int(mem_class_p.size());i++)
	{
		mem_class_p[i]->Labor_limit_up_conf(cpara->GET_PARA_max_e_flag());
		fprintf(cpara->FI_Get_Labor_writer(),"class=%d : eqw=%d : decided=%d , ",mem_class_p[i]->Get_class_no(),mem_class_p[i]->Get_eqw(),mem_class_p[i]->Labor_Get_decision());
	}
	fprintf(cpara->FI_Get_Labor_writer(),"\n");
}
void CProducer::Labor_calc_deicision()
{
	int i;
	fprintf(cpara->FI_Get_Labor_writer(),"�ݔ��A�ٗp�\�z���v�v�Z\n");
	for(i=0;i<int(mem_class_p.size());i++)
	{
		if(mem_class_p[i]->Labor_Get_decision()==1)
		{
			mem_class_p[i]->Labor_calc_decision();	
		}
	}
	

}
void CProducer::Labor_decision_limit_up_way()
{
	int i;
	int delta_rieki=0,cl_no=0;



	//��������̎菇
/*	�P�D���v�\���0
	�Q�D�����Ƃ����v������ꍇ�@���@���v���傫������I��
	�R�D�Е��̂ݗ��v������ꍇ�@���@���v������ꍇ��I���iA>0�AB<0�̎��AA�̔��肪��Ȃ��A>B�Ȃ̂�A�̂܂܁AB�̔��肪��Ȃ��B<A�Ȃ̂őI������A�Ɉڂ�j
	�S�D�������v���Ȃ����ꍇ�@�@���@���v��0�̂܂܁A�őI������way�������Ȃ���0�ɂȂ�̂œ������Ȃ����f
	�T�D���Ǝ҂����Ȃ��ꍇ�@�@�@���@���Ǝ҂Ȃ�=���v0�ɂȂ�

*/
	//��������X�g���N�`���̏�����
	delta_rieki=0;
	cl_no=9999;
	L_lud->limit_up_decide=0;
	L_lud->way=0;


	switch(cpara->Get_PARA_Labor_limit_up_decision_switch())
	{
	case 0:
		fprintf(cpara->FI_Get_Labor_writer(),"���Y�g��_�s�����f�_�u���v < 0�v_�N����\n");
		for(i=0;i<int(mem_class_p.size());i++)
		{
			if(delta_rieki<mem_class_p[i]->Labor_Get_delta_rieki_emp())
			{
				delta_rieki=mem_class_p[i]->Labor_Get_delta_rieki_emp();
				L_lud->limit_up_decide=1;
				L_lud->product_class=i;
				L_lud->way=1;
			}
			if(delta_rieki<mem_class_p[i]->Labor_Get_delta_rieki_inv())
			{
				delta_rieki=mem_class_p[i]->Labor_Get_delta_rieki_inv();
				L_lud->limit_up_decide=1;
				L_lud->product_class=i;
				L_lud->way=2;
			}
		}

		break;

	case 1:		//�@�\�z���v/���厑�{�@���@臒l����������ɉ�����ꍇ�B�@�@���{���O�̎��͏������Ȃ��@�@
		fprintf(cpara->FI_Get_Labor_writer(),"���Y�g��_�s�����f�_�u�\�z���v/���厑�{ > Labor_Labor_limit_up_basis�v_�N����\n");
		fprintf(cpara->FI_Get_Labor_writer(),"\n producer_no:%d , shihon:%d\n",Get_Agent_no(),cac.Get_kisyu_shihon_zandaka());
		for(i=0;i<int(mem_class_p.size());i++)
		{
			fprintf(cpara->FI_Get_Labor_writer(),"class_p:%d , rieki_emp:%d , rieki_emp/shihon:%lf\n",mem_class_p[i]->Get_class_no(),mem_class_p[i]->Labor_Get_delta_rieki_emp(),double(mem_class_p[i]->Labor_Get_delta_rieki_emp()/double(cac.Get_kisyu_shihon_zandaka())));
			fprintf(cpara->FI_Get_Labor_writer(),"class_p:%d , rieki_inv:%d , rieki_inv/shihon:%lf\n",mem_class_p[i]->Get_class_no(),mem_class_p[i]->Labor_Get_delta_rieki_inv(),double(mem_class_p[i]->Labor_Get_delta_rieki_inv()/double(cac.Get_kisyu_shihon_zandaka())));

			if(delta_rieki<mem_class_p[i]->Labor_Get_delta_rieki_emp()&&double(mem_class_p[i]->Labor_Get_delta_rieki_emp()/double(cac.Get_kisyu_shihon_zandaka()))>cpara->Get_PARA_Labor_Labor_limit_up_basis()&&cac.Get_kisyu_shihon_zandaka()>0)
			{
				delta_rieki=mem_class_p[i]->Labor_Get_delta_rieki_emp();
				L_lud->limit_up_decide=1;
				L_lud->product_class=i;
				L_lud->way=1;
				fprintf(cpara->FI_Get_Labor_writer(),"hit_emp!\n");
			}
			if(delta_rieki<mem_class_p[i]->Labor_Get_delta_rieki_inv()&&double(mem_class_p[i]->Labor_Get_delta_rieki_inv()/double(cac.Get_kisyu_shihon_zandaka()))>cpara->Get_PARA_Labor_Labor_limit_up_basis()&&cac.Get_kisyu_shihon_zandaka()>0)
			{
				delta_rieki=mem_class_p[i]->Labor_Get_delta_rieki_inv();
				L_lud->limit_up_decide=1;
				L_lud->product_class=i;
				L_lud->way=2;
				fprintf(cpara->FI_Get_Labor_writer(),"hit_inv!\n\n\n");
			}
		}
		break;


	case 2:		//�@�\�z���v/�������厑�{�@���@臒l����������ɉ�����ꍇ�B
		fprintf(cpara->FI_Get_Labor_writer(),"���Y�g��_�s�����f�_�u�\�z���v/�u�����v���厑�{ > Labor_Labor_limit_up_basis�v_�N����\n");
		fprintf(cpara->FI_Get_Labor_writer(),"\n producer_no:%d , shihon:%d\n",Get_Agent_no(),Get_shihon_ac());
		for(i=0;i<int(mem_class_p.size());i++)
		{
			fprintf(cpara->FI_Get_Labor_writer(),"class_p:%d , rieki_emp:%d , rieki_emp/shihon:%lf\n",mem_class_p[i]->Get_class_no(),mem_class_p[i]->Labor_Get_delta_rieki_emp(),double(mem_class_p[i]->Labor_Get_delta_rieki_emp()/double(Get_shihon_ac())));
			fprintf(cpara->FI_Get_Labor_writer(),"class_p:%d , rieki_inv:%d , rieki_inv/shihon:%lf\n",mem_class_p[i]->Get_class_no(),mem_class_p[i]->Labor_Get_delta_rieki_inv(),double(mem_class_p[i]->Labor_Get_delta_rieki_inv()/double(Get_shihon_ac())));

			if(delta_rieki<mem_class_p[i]->Labor_Get_delta_rieki_emp()&&double(mem_class_p[i]->Labor_Get_delta_rieki_emp()/double(Get_shihon_ac()))>cpara->Get_PARA_Labor_Labor_limit_up_basis())
			{
				delta_rieki=mem_class_p[i]->Labor_Get_delta_rieki_emp();
				L_lud->limit_up_decide=1;
				L_lud->product_class=i;
				L_lud->way=1;
				fprintf(cpara->FI_Get_Labor_writer(),"hit_emp!\n");
			}
			if(delta_rieki<mem_class_p[i]->Labor_Get_delta_rieki_inv()&&double(mem_class_p[i]->Labor_Get_delta_rieki_inv()/double(Get_shihon_ac()))>cpara->Get_PARA_Labor_Labor_limit_up_basis())
			{
				delta_rieki=mem_class_p[i]->Labor_Get_delta_rieki_inv();
				L_lud->limit_up_decide=1;
				L_lud->product_class=i;
				L_lud->way=2;
				fprintf(cpara->FI_Get_Labor_writer(),"hit_inv!\n\n\n");
			}
		}
		break;
	}

	if(L_lud->limit_up_decide==1)fprintf(cpara->FI_Get_Labor_writer(),"limit_up_decide:%d , class:%d , way:%d\n",L_lud->limit_up_decide,mem_class_p[L_lud->product_class]->Get_class_no(),L_lud->way);
}

template<class T>void  CProducer::Labor_Create_Jobs_info(T &mem_info)
{
	printf("wa=%d\n",L_lud->way);
	if(L_lud->way==1) //�g����@���@1���ٗp�̎�
	{
		cji->Set_fixed_salary(mem_class_p[L_lud->product_class]->Labor_Get_new_fixed_salary());
		cji->Set_Producer_rieki_zyouyo(mem_class_p[L_lud->product_class]->Labor_Get_riek_zyouyo());
		cji->Set_producer_no(Get_Agent_no());
		mem_info.push_back(cji);
	}
	
}

int CProducer::CR_Def_q_remodeling(int i,double max_q_re,double min_q_re,double Adjustment_Sensitivity)
{
	//�����̐��Y�ʂ����肵�ĕԂ�
	double beta=0.9;
	int j;
	int nstock;
	j=i;
	int ndata;//�w�����ꂽncr_p_i�Ԗڐ��i��ʏ��i�̎s��S�̂̐�
	int ndata_stock;//����c���Ă���ncr_p_i�Ԗڐ��i��ʏ��i�̎s��S�̂̐�
	int q_re;//revised amount of production amount
	ndata=mem_class_p[j]->Get_ndata();
	nstock=Get_nstock(j);
	ndata_stock=mem_class_p[j]->Get_ndata_stock();
	adj_sens=Adjustment_Sensitivity;//�������x
	q_re=mem_class_p[j]->Safe_q()+mem_class_p[j]->Expectation();
			//Safe_q()//���S�݌ɐ��i����Ԃ� 1.65sigma
			//Expectation();1���Y�҂�����̕��ϔ̔���
	switch(cpara->GET_PARA_CR_maxqre_decision_switch())
	{
	case 0:  //�������f�����胍�W�b�N
		if((nstock==0)&&(q_re>0))
		{
			q_re=int(q_re*max_q_re);
		}
		else
		{
			q_re=int(q_re*min_q_re);
			mem_class_p[j]->Set_eqw(-1);
			if(q_re<int(mem_class_p[j]->Get_q_limit()*beta))
			{
				//���Y�����O�ƂȂ�A���Y���~�t���O�𗧂Ă�ꍇ�͂�����
				mem_class_p[j]->Set_eqw(-1);
			}
		}
	break;

	case 1: //�����ݒ莞�����Œ�
		if((nstock==0)&&(q_re>0))
		{
			q_re=int(q_re*CR_max_q_re);
			fprintf(cpara->FI_Get_phenom_writer(),"CR_maxqre_decision_switch=1 , Pro_no=%d , class_no=%d , q_re=%d , max_q_re=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),q_re,CR_max_q_re);
		}
		else
		{
			q_re=int(q_re*CR_min_q_re);
			mem_class_p[j]->Set_eqw(-1);
			fprintf(cpara->FI_Get_phenom_writer(),"CR_maxqre_decision_switch=1 , Pro_no=%d , class_no=%d , q_re=%d , max_q_re=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),q_re,CR_min_q_re);
			if(q_re<int(mem_class_p[j]->Get_q_limit()*beta))
			{
				//���Y�����O�ƂȂ�A���Y���~�t���O�𗧂Ă�ꍇ�͂�����
				mem_class_p[j]->Set_eqw(-1);
			}
		}
	break;

	case 2://���莞��������
		if((nstock==0)&&(q_re>0))
		{
			double rate=cr->sdrand(cpara->GET_PARA_max_q_re()/2,cpara->GET_PARA_max_q_re());
			q_re=int(q_re*rate);
			fprintf(cpara->FI_Get_phenom_writer(),"CR_maxqre_decision_switch=1 , Pro_no=%d , class_no=%d , q_re=%d , max_q_re=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),q_re,rate);
		}
		else
		{
			double rate=cr->sdrand(cpara->GET_PARA_min_q_re()/2,cpara->GET_PARA_min_q_re());
			q_re=int(q_re*rate);
			mem_class_p[j]->Set_eqw(-1);
			fprintf(cpara->FI_Get_phenom_writer(),"CR_maxqre_decision_switch=1 , Pro_no=%d , class_no=%d , q_re=%d , max_q_re=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),q_re,rate);
			if(q_re<int(mem_class_p[j]->Get_q_limit()*beta))
			{
				//���Y�����O�ƂȂ�A���Y���~�t���O�𗧂Ă�ꍇ�͂�����
				mem_class_p[j]->Set_eqw(-1);
			}
		}
	break;

	case 3://max_q_re�n����g��Ȃ�

	break;
	}

	if(q_re>mem_class_p[j]->Get_q_limit())
		{
			//���Y�������Y���E�𒴂���A�ݔ������t���O�𗧂Ă�ꍇ�͍�����
			q_re=mem_class_p[j]->Get_q_limit();
			mem_class_p[j]->Set_eqw(1);//eqw:�ݔ������v���t���O
		}
	return q_re;
}
void CProducer::CR_New_set_price()
{
	int j;
	int price,max_price,min_price;
	double ave_price=0;
	int max_price_stock,min_price_stock;
	double ave_price_stock;
	int new_price=0;
	int flag;
	int koatarai_genryoukakaku=0;	//������̌������i
	int before_price,after_price;
	if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," Get_ncr_p=%d\n",mem_class_p.size());

	for(j=0;j<int(mem_class_p.size());j++)
	{
		koatarai_genryoukakaku=mem_class_p[j]->Get_koatari_genryouhi();
		
		max_price=Get_max_price(j);
		min_price=Get_min_price(j);
		ave_price=Get_ave_price(j);
		max_price_stock=mem_class_p[j]->Get_max_price_stock();
		min_price_stock=mem_class_p[j]->Get_min_price_stock();
		ave_price_stock=mem_class_p[j]->Get_ave_price_stock();
		price=Get_price(j);//����O�̉��i���擾����
		before_price=price;//�L�q�p
		flag=mem_class_p[j]->Get_flag();



		switch(cpara->GET_PARA_pricing_switch())
		{
		case 1:
			//���i�i�K���莮
			if(mem_class_p[j]->Get_nstock()==0)	//�݌ɂ��Ȃ��̂ŉ��i���㏸
			{
				price=int(price*1.05);//cpara->GET_PARA_max_price_p();
			}
			else 
			{
				if	(mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.5)	price=int(price*0.8);
				else if (mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.2) price=int(price*0.9);
				if(price<koatarai_genryoukakaku)	price=koatarai_genryoukakaku;
				if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," price_genka=%d , price=%d\n",koatarai_genryoukakaku,price);
			}
			Set_price(j,price);
			//���i�i�K���莮�I��
			break;

		case 2:
			//���i���͌}���^
			if(mem_class_p[j]->Get_nstock()==0)	//�݌ɂ��Ȃ��̂ŉ��i���㏸
			{
				price=int(price*1.1);
			}
			else 
			{
				if(price>max_price)	price=max_price;
				else price=int(price*0.9);

				if(price<koatarai_genryoukakaku)	price=koatarai_genryoukakaku;
				if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," price_genka=%d , price=%d\n",koatarai_genryoukakaku,price);
			}
			Set_price(j,price);
			//���i���͌}���^�I��
			break;

		case 3:
			//���i���͌}�������^
			new_price=0;
			if(mem_class_p[j]->Get_nstock()==0)	//�݌ɂ��Ȃ��̂ŉ��i���㏸
			{
				price=int(price*1.1);
			}
			else 
			{
				if(price>max_price)	
				{
					new_price=cr->strand(max_price,int(max_price*1.2));
					if(new_price<price)	price=new_price;
					else price=int(price*0.9);
				}
				else price=int(price*0.9);

				if(price<koatarai_genryoukakaku)	price=koatarai_genryoukakaku;
				if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," price_genka=%d , price=%d\n",koatarai_genryoukakaku,price);
			}
			Set_price(j,price);
			//���i���͌}�������^�I��
			break;

		case 4:
		//���i�}���i�K�����^
			new_price=0;
			if(mem_class_p[j]->Get_nstock()==0&&mem_class_p[j]->Get_last_buy_number()>0)	//�݌ɂ��Ȃ��̂ŉ��i���㏸
			{
				price=int(price*cpara->GET_PARA_price_up_rate());//1.15;//cpara->GET_PARA_max_price_p();
				fprintf(cpara->FI_Get_phenom_writer(),"pricing_switch=4 , Pro_no=%d , class_no=%d , price=%d , price_up_rate=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),price,cpara->GET_PARA_price_up_rate());
			}
			else 
			{
				new_price=int(max_price*cpara->GET_PARA_price_change_upper_rate());//*2.0;
				if(price>new_price)	
				{
					price=new_price;
				}
				else
				{
					if	(mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.5)	
					{
						price=int(price*(1-cpara->GET_PARA_price_down_rate()*2));//0.8;
						fprintf(cpara->FI_Get_phenom_writer(),"pricing_switch=4 , Pro_no=%d , class_no=%d , price=%d , price_down_rate*2=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),price,(1-cpara->GET_PARA_price_down_rate()*2));
					}
					else if (mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.2)
					{
						price=int(price*(1-cpara->GET_PARA_price_down_rate()*1));//0.9;
						fprintf(cpara->FI_Get_phenom_writer(),"pricing_switch=4 , Pro_no=%d , class_no=%d , price=%d , price_down_rate*1=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),price,(1-cpara->GET_PARA_price_down_rate()*1));
					}
				}

				if(price<koatarai_genryoukakaku)	price=koatarai_genryoukakaku;
				if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," price_genka=%d , price=%d\n",koatarai_genryoukakaku,price);

			}
			
			Set_price(j,price);
			fprintf(cpara->FI_Get_free_text(),"%d\n",mem_class_p[j]->Get_koatari_genryouhi());
		//���i�}���i�K�����^�I��
			break;

		case 5:
			//���i���蕝�����_�����e�i���O�����Œ�j���i�}���i�K�����^
			new_price=0;
			if(mem_class_p[j]->Get_nstock()==0&&mem_class_p[j]->Get_last_buy_number()>0)	//�݌ɂ��Ȃ��̂ŉ��i���㏸
			{
				price=int(price*CR_price_up_rate);//1.15;//cpara->GET_PARA_max_price_p();
				fprintf(cpara->FI_Get_phenom_writer(),"pricing_switch=5 , Pro_no=%d , class_no=%d , price=%d , price_up_rate=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),price,CR_price_up_rate);
			}
			else 
			{
				new_price=int(max_price*cpara->GET_PARA_price_change_upper_rate());//*2.0;
				if(price>new_price)	
				{
					price=new_price;
				}
				else
				{
					if	(mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.5)	
					{
						price=int(price*(1-CR_price_down_rate*2));//0.8;
						fprintf(cpara->FI_Get_phenom_writer(),"pricing_switch=5 , Pro_no=%d , class_no=%d , price=%d , price_down_rate*2=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),price,(1-CR_price_down_rate*2));
					}
					else if (mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.2) 
					{
						price=int(price*(1-CR_price_down_rate));//0.9;
						fprintf(cpara->FI_Get_phenom_writer(),"pricing_switch=5 , Pro_no=%d , class_no=%d , price=%d , price_down_rate=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),price,(1-CR_price_down_rate));
					}
				}

				if(price<koatarai_genryoukakaku)	price=koatarai_genryoukakaku;
				if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," price_genka=%d , price=%d\n",koatarai_genryoukakaku,price);
			}
			Set_price(j,price);
			fprintf(cpara->FI_Get_free_text(),"%d\n",mem_class_p[j]->Get_koatari_genryouhi());
		//���i���蕝�����_�����e�i���O�����Œ�j���i�}���i�K�����^�I��
			break;

		case 6:
			//���i���蕝�����_�����e�i���莞�����j���i�}���i�K�����^
			new_price=0;
			double rate=0;
			if(mem_class_p[j]->Get_nstock()==0&&mem_class_p[j]->Get_last_buy_number()>0)	//�݌ɂ��Ȃ��̂ŉ��i���㏸
			{
				rate=cr->sdrand(cpara->GET_PARA_price_up_rate()/2,cpara->GET_PARA_price_up_rate());
				price=int(price*rate);//1.15;//cpara->GET_PARA_max_price_p();
				fprintf(cpara->FI_Get_phenom_writer(),"pricing_switch=6 , Pro_no=%d , class_no=%d , price=%d , price_up_rate=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),price,rate);
			}
			else 
			{
				new_price=int(max_price*cpara->GET_PARA_price_change_upper_rate());//*2.0;
				if(price>new_price)	
				{
					price=new_price;
				}
				else
				{
					if	(mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.5)	
					{
						rate=cr->sdrand(cpara->GET_PARA_price_down_rate(),cpara->GET_PARA_price_down_rate()*2);
						price=int(price*(1-rate));//0.8;
						fprintf(cpara->FI_Get_phenom_writer(),"pricing_switch=6 , Pro_no=%d , class_no=%d , price=%d , price_down_rate*2=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),price,rate);
					}
					else if (mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.2) 
					{
						rate=cr->sdrand(cpara->GET_PARA_price_down_rate()*0.5,cpara->GET_PARA_price_down_rate()*1);
						price=int(price*(1-rate));//0.9;
						fprintf(cpara->FI_Get_phenom_writer(),"pricing_switch=6 , Pro_no=%d , class_no=%d , price=%d , price_down_rate=%lf\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),price,rate);
					}
				}

				if(price<koatarai_genryoukakaku)	price=koatarai_genryoukakaku;
				if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," price_genka=%d , price=%d\n",koatarai_genryoukakaku,price);
			}
			Set_price(j,price);
			fprintf(cpara->FI_Get_free_text(),"%d\n",mem_class_p[j]->Get_koatari_genryouhi());
		//���i���蕝�����_�����e�i���莞�����j���i�}���i�K�����^�I��
			break;



		}//  switch end

		after_price=price;
		fprintf(cpara->FI_Get_phenom_writer(),"New_set_price , agent_no:%d , class_no:%d , before_price:%d , after_price:%d\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),before_price,after_price);
		
	}
}
void CProducer::CR_Seisan_plan_revised(vector <CProduct *>mem_product_whole,double max_q_re,double min_q_re,double Adjustment_Sensitivity)
{
	//���Y�v��𗧂Ă�
	//���Y���鐻�i��ʂ̐��Fncr_p
	int i;
	int nstock;
	int q0,sumq=0;
	int sum=0;

	for(i=0;i<int(mem_employ_const_wage.size());i++)
	{
		sum+=mem_employ_const_wage[i];
	}
	total_constant_wage=sum;//�]�ƈ��̌Œ苋�^�̑��z
	fprintf(cpara->FI_Get_employ_file(),"ag=%d , aaaaaaaaaaaemploy_ size %d , sum=%d \n",Get_Agent_no(),mem_employ_const_wage.size(),total_constant_wage);
	Set_total_constant_wage(total_constant_wage);
	Set_total_price_genka(total_constant_wage);



	//���Y�ʂ����肷��
	

	for(i=0;i<int(mem_class_p.size());i++)
	{
		
		nstock=mem_class_p[i]->Get_nstock();
		q0=CR_Def_q_remodeling(i,max_q_re,min_q_re,Adjustment_Sensitivity);//q0=ave+1.65sigma�Ƃ���Bave=1���Y�҂�����̕��ϔ̔���
		
		if(cpara->GET_PARA_CR_q_limit_down_line_switch()==0)			//CR_q_limit_down_line_switch��0�ł����q_limit��7���͍݌ɂ�����
			if(q0<int(mem_class_p[i]->Get_q_limit()*0.7))	q0=int(mem_class_p[i]->Get_q_limit()*0.7);

		if(nstock>0)
		{
			if(q0>nstock) 
			{
				mem_class_p[i]->Set_q(q0-nstock);
				mem_class_p[i]->Set_material_need(q0-nstock);
				mem_class_p[i]->Flag_down();//f_down++;���i�t���O��������
			}
			else 
			{
				mem_class_p[i]->Set_q(0);
				mem_class_p[i]->Set_material_need(0);
				mem_class_p[i]->Flag_down();//���i�t���O��������
				mem_class_p[i]->Flag_down();//�啝�ɏd�v���������̂��߉��i�t���O��2�{������
				mem_class_p[i]->Set_bankrup();
			}
		}
		else if(mem_class_p[i]->Get_last_buy_number()>0) //�݌ɂȂ�
		{
			mem_class_p[i]->Set_q(q0);
			mem_class_p[i]->Set_material_need(q0);
			mem_class_p[i]->Flag_up();//���i�t���O���㏸������
			mem_class_p[i]->Set_bankrup_d();
		}
		else
		{
			mem_class_p[i]->Set_q(5);
			mem_class_p[i]->Set_material_need(5);
			mem_class_p[i]->Flag_down();//���i�t���O���㏸������
			mem_class_p[i]->Set_bankrup();
			mem_class_p[i]->Set_bankrup();
		}
		if(Get_Agent_no()==12)	fprintf(cpara->FI_Get_se_income_new(),"no=%d , class_no=%d , buy=%d , q=%d , banker=%d\n",Get_Agent_no(),mem_class_p[i]->Get_class_no(),mem_class_p[i]->Get_last_buy_number(),mem_class_p[i]->Get_q(),mem_class_p[i]->Get_bankrup());
	}

}

void CProducer::CR_set_koatari_genka()
{
	int i;
	for(i=0;i<ncr_p;i++)
	{
		mem_class_p[i]->CR_Set_koatari_genryouhi(cr->strand(cpara->GET_PARA_CR_limit_genka_down(),cpara->GET_PARA_CR_limit_genka_up()));
	}
}
void CProducer::CR_seisan_plan()
{
		//���Y�v��𗧂Ă�
	//���Y���鐻�i��ʖ��ɐ��Y�ʁA���i�����肷��
	//���͉��i�͍l���Ȃ�
	//���Y���鐻�i��ʂ̐��Fncr_p
	int i;
	int price;
	int price_genka;
	int sum_price=0;
	int sumq=0;
	int size;
	size=mem_employ.size();
	int sum=0;

	for(i=0;i<ncr_p;i++)//���Y�ʂ�ݒ肷��
	{
		mem_class_p[i]->Set_q(Get_class_q_limit(i));
	}

	//���i�����肷��
	for(i=0;i<ncr_p;i++){
		Set_price_genka(mem_class_p[i]->CR_Get_koatari_genryouhi());			//�����̐ݒ� �`�`�`�����̓p�����[�^���玝���Ă���`�`�`

		price=cpara->GET_PARA_first_price();	//�������i�̐ݒ�
		price_genka=mem_class_p[i]->CR_Get_koatari_genryouhi();

		mem_class_p[i]->Set_price(price);
		mem_class_p[i]->Set_price_genka(mem_class_p[i]->CR_Get_koatari_genryouhi());//���i�P������̌���
		mem_class_p[i]->Set_koatari_genryouhi(mem_class_p[i]->CR_Get_koatari_genryouhi());
		sum_price=mem_class_p[i]->CR_Get_koatari_genryouhi()*sumq;
		fprintf(cpara->FI_Get_seisan()," price_genka=%d price=%d sumq=%d ncr_p=%d q=%d sum_price_genka=%d�@total_price_genka=%d\n",price_genka,price,sumq,ncr_p,mem_class_p[i]->Get_q(),sum_price,Get_total_price_genka());
	}
	Set_sum_price_genka(sum_price);

}

void CProducer::CR_seisan()
{
	
	//�����ȍ~���Y
	int i,j;
	int x;
	int no;
	int q;
	vector <CProduct *>::iterator del_wp;
	fprintf(cpara->FI_Get_retai()," , pron= %d\n",Producer_no);

	for(i=0;i<ncr_p;i++)
	{
		x=0;
		no=0;
		q=mem_class_p[i]->Get_q();
		fprintf(cpara->FI_Get_retai()," , class=%d , q=%d , ",mem_class_p[i]->Get_class_no(),q);
		mem_class_p[i]->Erase_mem_seihin();

		for(j=0;j<q;j++)
		{
			mem_class_p[i]->Create_product_revised(j);
			no++;
		}
		mem_class_p[i]->Set_nop(no);
	}
	nop_sum=0;
	for(i=0;i<ncr_p;i++)
	{
		nop_sum+=mem_class_p[i]->Get_nop();
	}
}

void CProducer::First_set_q()
{
	int i;
	for(i=0;i<int(mem_class_p.size());i++)
	{
		mem_class_p[i]->Set_q(mem_class_p[i]->Get_q_limit());
		mem_class_p[i]->Set_material_need(mem_class_p[i]->Get_q_limit());
	}
}
void CProducer::Set_shiwake_pay_bonus(int i_period,int amount)
{
	cac.Set_shiwake(i_period,0,"�{�[�i�X","�ŋ��x��","����",amount,1,0);
	cac.Set_shiharai_bonus(amount);
}

int CProducer::Get_repay_loan_l_and_int()
{
	int out,loan_l=0,inte=0;
	if(int(repay_loan_l.size())>0)
	{
		loan_l=repay_loan_l[0];
		inte=repay_inte_l[0];
	}
	out=loan_l+inte;
	return out;
}

void CProducer::New_set_price()
{
	int j;
	int price,max_price,min_price;
	double ave_price=0;
	int max_price_stock,min_price_stock;
	double ave_price_stock;
	int new_price=0;
	int flag;
	int koatarai_genryoukakaku=0;	//������̌������i
	int before_price,after_price;
	if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," Get_ncr_p=%d\n",mem_class_p.size());

	for(j=0;j<int(mem_class_p.size());j++)
	{
		koatarai_genryoukakaku=mem_class_p[j]->Get_koatari_genryouhi();
		
		max_price=Get_max_price(j);
		min_price=Get_min_price(j);
		ave_price=Get_ave_price(j);
		max_price_stock=mem_class_p[j]->Get_max_price_stock();
		min_price_stock=mem_class_p[j]->Get_min_price_stock();
		ave_price_stock=mem_class_p[j]->Get_ave_price_stock();
		price=Get_price(j);//����O�̉��i���擾����
		before_price=price;//�L�q�p
		flag=mem_class_p[j]->Get_flag();



		switch(cpara->GET_PARA_pricing_switch())
		{
		case 1:
			//���i�i�K���莮
			if(mem_class_p[j]->Get_nstock()==0)	//�݌ɂ��Ȃ��̂ŉ��i���㏸
			{
				price=int(price*1.05);
			}
			else 
			{
				if	(mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.5)	price=int(price*0.8);
				else if (mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.2) price=int(price*0.9);

				if(price<koatarai_genryoukakaku)	price=koatarai_genryoukakaku;
				if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," price_genka=%d , price=%d\n",koatarai_genryoukakaku,price);
			}
			Set_price(j,price);
			//���i�i�K���莮�I��
			break;

		case 2:
			//���i���͌}���^
			if(mem_class_p[j]->Get_nstock()==0)	//�݌ɂ��Ȃ��̂ŉ��i���㏸
			{
				price=int(price*1.1);
			}
			else 
			{
				if(price>max_price)	price=max_price;
				else price=int(price*0.9);

				if(price<koatarai_genryoukakaku)	price=koatarai_genryoukakaku;
				if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," price_genka=%d , price=%d\n",koatarai_genryoukakaku,price);
			}
			Set_price(j,price);
			//���i���͌}���^�I��
			break;

		case 3:
			//���i���͌}�������^
			new_price=0;
			if(mem_class_p[j]->Get_nstock()==0)	//�݌ɂ��Ȃ��̂ŉ��i���㏸
			{
				price=int(price*1.1);
			}
			else 
			{
				if(price>max_price)	
				{
					new_price=cr->strand(max_price,int(max_price*1.2));
					if(new_price<price)	price=new_price;
					else price=int(price*0.9);
				}
				else price=int(price*0.9);

				if(price<koatarai_genryoukakaku)	price=koatarai_genryoukakaku;
				if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," price_genka=%d , price=%d\n",koatarai_genryoukakaku,price);
			}
			Set_price(j,price);
			//���i���͌}�������^�I��
			break;

		case 4:
		//���i�}���i�K�����^
			new_price=0;
			if(mem_class_p[j]->Get_nstock()==0&&mem_class_p[j]->Get_last_buy_number()>0)	//�݌ɂ��Ȃ��̂ŉ��i���㏸
			{
				price=int(price*cpara->GET_PARA_price_up_rate());//1.15;//cpara->GET_PARA_max_price_p();
			}
			else 
			{
				new_price=int(max_price*cpara->GET_PARA_price_change_upper_rate());//*2.0;
				if(price>new_price)	
				{
					price=new_price;
				}
				else
				{
					if	(mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.5)	price=int(price*(1-cpara->GET_PARA_price_down_rate()*2));//0.8;
					else if (mem_class_p[j]->Get_nstock()>mem_class_p[j]->Get_q_limit()*0.2) price=int(price*(1-cpara->GET_PARA_price_down_rate()*1));//0.9;
				}

				if(price<koatarai_genryoukakaku)	price=koatarai_genryoukakaku;
				if(Agent_type==30)	fprintf(cpara->FI_Get_seisan()," price_genka=%d , price=%d\n",koatarai_genryoukakaku,price);
			}
			Set_price(j,price);
		//���i�}���i�K�����^�I��
			break;
		}//  switch end

		after_price=price;
		fprintf(cpara->FI_Get_phenom_writer(),"New_set_price , agent_no:%d , class_no:%d , before_price:%d , after_price:%d\n",Get_Agent_no(),mem_class_p[j]->Get_class_no(),before_price,after_price);
		
	}
}
void CProducer::Decide_dismisses()
{
	int konki_rieki=0;
	konki_rieki=cac.Get_touki_zeimae_rieki();

	if(konki_rieki<0)	loan_time++;		//���v���}�C�i�X�Ȃ�t���O�𗧂Ă�
	else				loan_time=loan_time-1;//���v���v���X�Ȃ�t���O��������
	
	if(loan_time<0)	loan_time=0;
	fprintf(cpara->FI_Get_se_con(),"%d , %d , %d\n",loan_time,loan_time_limit,cac.Get_loan_point());
	if(loan_time_limit<loan_time)
	{
		if(mem_employ.size()>1)
		{	
			fprintf(cpara->FI_Get_employ_file(),"const_wage   %d , %d\n",mem_employ.size(),mem_employ_const_wage.size());
			dismiss_flag=1;
			dismiss_no=mem_employ[mem_employ.size()-1];
			loan_time=0;
			mem_employ.pop_back();
			mem_employ_const_wage.pop_back();
			fprintf(cpara->FI_Get_employ_file(),"const_wage   %d , %d\n",mem_employ.size(),mem_employ_const_wage.size());
		}
		else 
		{
			dismiss_flag=0;
			dismiss_no=99999999;
		}
	}
	else
	{
		dismiss_flag=0;
		dismiss_no=99999999;
	}

}
void CProducer::Adjust_q_init(int x)
{
	int q_limit,q_init;
	q_limit=mem_class_p[x]->Get_q_limit();
	q_init=mem_class_p[x]->Get_q_init();
	if(q_limit<q_init)	mem_class_p[x]->Set_q_init(q_limit);
}
void CProducer::Adjust_q(int x)
{
	int q_limit,q;
	q_limit=mem_class_p[x]->Get_q_limit();
	q=mem_class_p[x]->Get_q();
	if(q_limit<q)	mem_class_p[x]->Set_q(q_limit);
}

void CProducer::Repayment()
{
	vector<int>::iterator p;
	p=repay_loan_l.begin();
	repay_loan_l.erase(p);
	p=repay_inte_l.begin();
	repay_inte_l.erase(p);
}
void CProducer::Set_loan_re(int lo,int in)
{
	//lo:�������̃��[���c�z
	//in:�������̎x������
		repay_loan_l.push_back(lo);//�����̃��[���ԍϊz�̏W��
		repay_inte_l.push_back(in);//�������̎x�������̏W��
}

void CProducer::Set_shiwake_seisan_k(int i_period,int p_gen,int pay_b)
{
	cac.Set_shiwake(i_period,p_gen,"����","�������Y","������p",p_gen,1,2);
	cac.Set_shiwake(i_period,p_gen,"�J����","�������Y","����",p_gen,1,1);
	cac.Set_shiwake(i_period,pay_b,"�{�[�i�X��","�������Y","������p",pay_b,1,2);
	cac.Set_shiwake(i_period,pay_b,"��ʊǗ���","�������Y","�{�[�i�X��",pay_b,1,1);
	cac.Set_shiwake(i_period,p_gen,"���㌴��","�������Y","�J����",p_gen,1,1);
}
void CProducer::Set_shiwake_seisan_k(int i_period,int p_gen)
{
	cac.Set_shiwake(i_period,p_gen,"����","�������Y","������p",p_gen,1,2);
	cac.Set_shiwake(i_period,p_gen,"�J����","�������Y","����",p_gen,1,1);
	cac.Set_shiwake(i_period,p_gen,"���㌴��","�������Y","�J����",p_gen,1,1);
}
void CProducer::Set_material_need()
{
	int i;
	for(i=0;i<ncr_p;i++)
	{
		mem_class_p[i]->Set_material_need(mem_class_p[i]->Get_q());
	}
}
void CProducer::Set_rieki(int x)
{
	rieki+=x;//���Y�җ��v��x��������������
}
int CProducer::Get_mem_class_p_size()
{
	int size;
	size=mem_class_p.size();
	return size;
}

void CProducer::Set_IC()
{
	capital=0;									//�����̏������i���Ԃ񌻍ݖ��g�p�j2012_02_18
	rieki=0;									//���v�̏������i���݂̎g�p�͕s���j2012_02_18
	e_flag=cpara->GET_PARA_max_e_flag();		//�ݔ������t���O�i���x�t���O�j�̐ݒ�2012_02_18
	equip_end=cpara->GET_PARA_max_equip_end();	//�ݔ��̑ϗp�N���ݒ�i���ݖ��g�p�A���㗘�p�\��j2012_02_18
	ncr_p=0;					//
	loan_time=0;				//
	min_genka_whole=cpara->GET_PARA_min_genka_whole();
	
	L_lud =new Labor_limit_up_data;

	cji=new CJob_info;
}

void CProducer::bankr(int max_ban)
{
	int i,j;
	int size;
	int ban;
	int ban_no;
	vector <CProduct_class *> ::iterator p;
	size=mem_class_p.size();
	p=mem_class_p.begin();
	for(i=0;i<size;i++)
	{
		ban_no=0;
		p=mem_class_p.begin();
		for(j=0;j<size;j++)	
		{
			if(ban_no==i)
			{
				break;
			}
			p++;
			ban_no++;
		}

		ban=mem_class_p[i]->Get_bankrup();//���Y���i��ʂ̔p�Ǝw��
		if(Agent_no==13) fprintf(cpara->FI_Get_tax(),"agn= , %d ,class_no= ,  %d ,ban= ,  %d , price= , %d , nstock= , %d\n",Agent_no,mem_class_p[i]->Get_class_no(),ban,mem_class_p[i]->Get_price(),mem_class_p[i]->Get_nstock());
		if(ban>=max_ban)
		{
			p=mem_class_p.erase(p);//printf("test\n");
			ncr_p=mem_class_p.size();
			break;
		}
	}
}
int CProducer::Get_g_eqw_no()
{
	int no;
	no=cr->strand(0,ncr_p-1);
	return no;
}

int CProducer::Get_eqw_no()
{
	//�����Ώۂ̐��i��ʂ�Ԃ�
	int i;
	int ri=0;
	int no;

	for(i=0;i<ncr_p;i++)
	{
		if(mem_class_p[i]->Get_eqw()>=e_flag)
		{
			if(ri<mem_class_p[i]->Get_rieki())//rieki;//�����̗��v
			{
				//���Y���i��ʂ̗��v���������Ă���Η��v�ő�̐��i��ʂ�I��
				no=i;
				ri=mem_class_p[i]->Get_rieki();
			}
		}
	}
	if(ri<=0)
	{
		for(i=0;i<ncr_p;i++)//ncr_p:�e���Y�҂����Y���鐻�i��ʂ̐�
		{
			if(mem_class_p[i]->Get_eqw()>=e_flag)
			{
				no=i;
				break;
			}
		}
	}
	mem_class_p[no]->Reset_eqw();
	return no;

}

int CProducer::Get_eqw()
{
	int i;
	int eq_flag=0;
	for(i=0;i<ncr_p;i++)
	{
		if(mem_class_p[i]->Get_eqw()>=e_flag) eq_flag=1;
		fprintf(cpara->FI_Get_eqw(),"%d,",mem_class_p[i]->Get_eqw());
	}	fprintf(cpara->FI_Get_eqw(),"\n");
	return eq_flag;
}
int CProducer::Get_cost()
{
	int i;
	int cost=0;
	int prof;
	for(i=0;i<ncr_p;i++)
	{
		prof=mem_class_p[i]->Get_price()*mem_class_p[i]->Get_buy()-mem_class_p[i]->Get_price_genka()*mem_class_p[i]->Get_buy();
		mem_class_p[i]->Set_rieki(prof);
		cost+=mem_class_p[i]->Get_price_genka()*mem_class_p[i]->Get_buy();
	}
	return cost;
}
void CProducer::Set_rieki(int ri,int i)
{
	rieki+=ri;
	int j;
	for(j=0;j<ncr_p;j++)
	{
		if(i==mem_class_p[j]->Get_class_no())	
		{
			mem_class_p[j]->Set_buy();
		}
	}
}
void CProducer::Clear_p_class()
{
	int i,size;
	size=mem_class_p.size();
	for(i=0;i<size;i++)
	{
		mem_class_p[i]->clear_buy();//buy��market_buy�ɓ����
				//buy:�Y�����i�̎��Д̔���
	}
}
void CProducer::Clear_p_class_w()
{
	int i,size;
	size=mem_class_p.size();
	for(i=0;i<size;i++)
	{
		mem_class_p[i]->clear_buy();
	}
}



int CProducer::Get_nop(int i)
{
	return mem_class_p[i]->Get_nop();
}


void CProducer::Def_flag_price_w(int ncr_p_i,double price_increase_rate)
{
	int j;
	j=ncr_p_i;
	double x=price_increase_rate;
	int price,max_price,min_price;
	double ave_price=0;
	int max_price_stock,min_price_stock;
	double ave_price_stock;
	int price_genka;
	int flag;
	price_genka=mem_class_p[j]->Get_price_genka();
			max_price=Get_max_price(j);//mem_class_p[ncr_p_i]��max_price�����o��
			min_price=Get_min_price(j);
			ave_price=Get_ave_price(j);
			max_price_stock=mem_class_p[j]->Get_max_price_stock();
			min_price_stock=mem_class_p[j]->Get_min_price_stock();
			ave_price_stock=mem_class_p[j]->Get_ave_price_stock();
			price=Get_price(j);//����O�̉��i���擾����
	flag=mem_class_p[j]->Get_flag();

	if(flag==1)
	{
		//flag=1�Areac_flag<=f_up in Get_flag() �݌ɑ��Y�����𐔓x�s���Ă��邽�߉��i���グ��
		if(price==max_price) price=cr->strand(price,int((1+x)*price));
		else if(price<ave_price) price=cr->strand(price,int(ave_price*(1+x)));
		else price=cr->strand(price,max_price);
	}
	else if(flag==2)
	{
		//flag=2�Areac_flag<=f_down �݌ɏk�������𐔓x�s���Ă��邽�߉��i��������
		if(price>ave_price_stock)
		{
			price=cr->strand(int(ave_price_stock*(1-x)),price);
			if(price<price_genka) 
			{
				price=price_genka;
				mem_class_p[j]->Set_bankrup();
			}
		}
		else 
		{
			price=cr->strand(price,int(min_price_stock*(1-x)));
			if(price<price_genka)
			{
				price=price_genka;
				mem_class_p[j]->Set_bankrup();
			}
		}
	}
	else if(flag==0)
	{//�݌Ƀt���O�������Ă��Ȃ����ߓK���Ɣ��f,���i�͕ύX���Ȃ�
	}
	else printf("aaaaaaaaaaaaa\n");
	Set_price(j,price);
	fprintf(cpara->FI_Get_seisan()," price_genka=%d\n",price_genka);
}
void CProducer::Def_flag_price(int ncr_p_i,double p_in_rate,double min_p,double max_p,double min_m,double max_m)
{
	int j;
	j=ncr_p_i;
	double x=p_in_rate;
	int price,max_price,min_price;
	double ave_price=0;
	int max_price_stock,min_price_stock;
	double ave_price_stock;
	int price_genka;
	int flag;
	price_genka=mem_class_p[j]->Get_limit_genka();
	max_price=Get_max_price(j);
	min_price=Get_min_price(j);
	ave_price=Get_ave_price(j);
	max_price_stock=mem_class_p[j]->Get_max_price_stock();
	min_price_stock=mem_class_p[j]->Get_min_price_stock();
	ave_price_stock=mem_class_p[j]->Get_ave_price_stock();
	price=Get_price(j);//����O�̉��i���擾����
	flag=mem_class_p[j]->Get_flag();
	if(Producer_no==5) {
		printf("flag=%d\n",flag);
	}
	if(flag==1)
	{
		//flag=1�A�݌ɑ��Y�����𐔓x�s���Ă��邽�߉��i���グ��
		price=cr->strand(int(price*min_p),int(price*max_p));
	}
	else if(flag==2)
	{
		//flag=2�A�݌ɏk�������𐔓x�s���Ă��邽�߉��i��������
		if(price>ave_price)
		{
			price=cr->strand(price,int(ave_price));
			if(price<price_genka) 
			{
				price=price_genka;
			}
		}
		else
		{
			price=cr->strand(int(price*min_m),int(price*max_m));
			if(price<price_genka) 
			{
				price=price_genka;
			}
		}
	}
	else if(flag==0)
	{//�݌Ƀt���O�������Ă��Ȃ����ߓK���Ɣ��f
	}
	else printf("aaaaaaaaaaaaa\n");
	Set_price(j,price);
	fprintf(cpara->FI_Get_seisan()," price_genka=%d\n",price_genka);
}
void CProducer::Define_revised_price(int ncr_p_i)
{
//mem_class_p[ncr_p_i]�̉��艿�i�����肷��
	int ncase;
		//ncase=0: min_stock_price*(1-alpha)���ŉ��i�����肷��
		//ncase=1: (price+min_stock_price*(1-alpha))/2���ŉ��肷��
		//ncase=2: strand(price,min_stock_price*(1-alpha))�ŉ��肷��
	ncase=2;
	int j;
	int nstock;
	j=ncr_p_i;
	double x=0.02;
	int price,max_price,min_price;
	double ave_price=0;
	int max_price_stock,min_price_stock;
	double ave_price_stock;
	int ndata;//�w�����ꂽncr_p_i�Ԗڐ��i��ʏ��i�̎s��S�̂̐�
	int ndata_stock;//����c���Ă���ncr_p_i�Ԗڐ��i��ʏ��i�̎s��S�̂̐�
	int price_genka;
	price_genka=mem_class_p[j]->Get_price_genka();
			max_price=Get_max_price(j);
			min_price=Get_min_price(j);
			ave_price=Get_ave_price(j);
			ndata=mem_class_p[j]->Get_ndata();
			nstock=Get_nstock(j);
			max_price_stock=mem_class_p[j]->Get_max_price_stock();
			min_price_stock=mem_class_p[j]->Get_min_price_stock();
			ave_price_stock=mem_class_p[j]->Get_ave_price_stock();
			ndata_stock=mem_class_p[j]->Get_ndata_stock();
			price=Get_price(j);//����O�̉��i���擾����

		if(ncase==2)
		{
			if(ndata_stock==0)
			{
				//���Y���i��ʂ̔���c��͎s��ɑ��݂��Ȃ�
				//���i��l�グ����
				if(price==max_price) price=cr->strand(price,int((1+x)*price));
				else if(price<ave_price) price=cr->strand(price,int(ave_price*(1+x)));
				else price=cr->strand(price,max_price);
			}
			else
			{
				if(nstock==0) price=cr->strand(price,int(min_price_stock*(1-x)));
				else if(price>ave_price_stock)
				{
					price=cr->strand(int(ave_price_stock*(1-x)),price);
					if(price<price_genka) price=price_genka;
				}
				else 
				{
					price=cr->strand(price,int(min_price_stock*(1-x)));
					if(price<price_genka) price=price_genka;
				}
			}
		}
				
		Set_price(j,price);
}
void CProducer::Renew_stock_price(vector <CProduct *> mem_product)
{
	int i,j,nj;
	int size;
	int class_no;
	int price;
	int price_dif;
	int nerror;
	size=mem_product.size();
	int ncr_p;
	ncr_p=mem_class_p.size();
	for(i=0;i<size;i++)
	{
		nerror=0;
		class_no=mem_product[i]->Get_class_no();
		for(j=0;j<ncr_p;j++)
		{
			if(mem_class_p[j]->Get_class_no()==class_no && mem_product[i]->Get_Producer_no()==Producer_no)
			{
				nj=j;
				price=mem_class_p[nj]->Get_price();
				price_dif=price-mem_product[i]->Get_price();
				mem_product[i]->Set_price(price);//����c�萻�i�̉��i�����肷��
			}//if(mem_class_p[j]....�̏I���
		}//for(j=0;j<ncr_p...�̏I���
	}
}
int CProducer::Get_max_price(int ncr_p_i)
{
	//mem_class_p[ncr_p_i]��max_price�����o��
	return mem_class_p[ncr_p_i]->Get_max_price();
}
int CProducer::Get_min_price(int ncr_p_i)
{
	//mem_class_p[ncr_p_i]��min_price�����o��
	return mem_class_p[ncr_p_i]->Get_min_price();
}
double CProducer::Get_ave_price(int ncr_p_i)
{
	//mem_class_p[ncr_p_i]��ave_price�����o��
	return mem_class_p[ncr_p_i]->Get_ave_price();
}
int CProducer::Get_nstock(int ncr_p_i)
{
	//mem_class_p[ncr_p_i]��nstock(����c�萔)�����o��
	return mem_class_p[ncr_p_i]->Get_nstock();
}
int CProducer::Get_price(int ncr_p_i){
	//mem_class_p[ncr_p_i]��price�����o��
	return mem_class_p[ncr_p_i]->Get_price();
}

void CProducer::Set_price(int ncr_p_i,int price1)
{
	//mem_class_p[ncr_p_i]��price��price1������
	mem_class_p[ncr_p_i]->Set_price(price1);
}
void CProducer::Def_stock(vector <CProduct *> mem_product)
{
	//�s��̔���c�菤�i�̐��𒲂ׂ�
	int i,j;
	int ncon;
	int size;
	size=mem_product.size();
	int size_ncr;
	size_ncr=mem_class_p.size();
	for(i=0;i<size_ncr;i++){
		ncon=0;
		for(j=0;j<size;j++){
			if(mem_product[j]->Get_class_no()==mem_class_p[i]->Get_class_no())
			{
				if(mem_product[j]->Get_Producer_no()==mem_class_p[i]->Get_Producer_no())
				{
					ncon++;
				}
			}
		}
		mem_class_p[i]->Set_nstock(ncon);//�s��ɂ��鏤�i�̐���nstock�ɂ����
//		printf("%d\n",ncon);
	}

}
void CProducer::Show_stock()
{
	int i;
	int size;
	size=mem_class_p.size();
	for(i=0;i<size;i++){
		fprintf(cpara->FI_Get_out(),"producer_no=,%3d, class_no=,%3d, q=,%3d, nstock=,%3d, price=,%6d, ave_price=,%6.1f\n",
			Producer_no,mem_class_p[i]->Get_class_no(),mem_class_p[i]->Get_q(),mem_class_p[i]->Get_nstock(),mem_class_p[i]->Get_price(),mem_class_p[i]->Get_ave_price());
	}

}
void CProducer::Show_price_statics()
{
	int i;
	int size;
	size=mem_class_p.size();
	for(i=0;i<size;i++)
	{
		fprintf(cpara->FI_Get_out(),"Producer_no=,%3d, class_no=,%3d, q=,%3d, price=,%6d, ave_price=,%6.1f, max_price=,%6d, min_price_stock=,%6d,\n",Producer_no,mem_class_p[i]->Get_class_no(),mem_class_p[i]->Get_q(),mem_class_p[i]->Get_price(),mem_class_p[i]->Get_ave_price(),mem_class_p[i]->Get_max_price(),mem_class_p[i]->Get_min_price_stock());
	}
}
void CProducer::Def_stock_price_statics(vector <CProduct_class *> mem_class_stock_statics)
{
	//�eproducer��mem_class_p�̕ϐ��ɍ݌ɐ��i���v���f�[�^�������
	int i,j;
	int size;
	size=mem_class_stock_statics.size();
	int size_ncr;
	size_ncr=mem_class_p.size();
	for(i=0;i<size_ncr;i++){
		for(j=0;j<size;j++){
			if(mem_class_stock_statics[j]->Get_class_no()==mem_class_p[i]->Get_class_no())
			{
				mem_class_p[i]->Set_max_price_stock(mem_class_stock_statics[j]->Get_max_price_stock());
				mem_class_p[i]->Set_min_price_stock(mem_class_stock_statics[j]->Get_min_price_stock());
				mem_class_p[i]->Set_ave_price_stock(int(mem_class_stock_statics[j]->Get_ave_price_stock()));	
				mem_class_p[i]->Set_ndata_stock(mem_class_stock_statics[j]->Get_ndata_stock());
	
			}
		}
	}
}
void CProducer::Def_price_statics(vector <CProduct_class *> mem_class_statics)
{
	//�eproducer��mem_class_p�̕ϐ��ɓ��v���f�[�^�������
	int i,j;
	int size;
	size=mem_class_statics.size();
	int size_ncr;
	size_ncr=mem_class_p.size();
//	printf("size=%d,size_ncr=%d\n",size,size_ncr);
	for(i=0;i<size_ncr;i++)
	{
		for(j=0;j<size;j++)
		{
			if(mem_class_statics[j]->Get_class_no()==mem_class_p[i]->Get_class_no())
			{
//				printf("%d,%d,%lf\n",mem_class_statics[j]->Get_max_price());
				mem_class_p[i]->Set_max_price(mem_class_statics[j]->Get_max_price());
				mem_class_p[i]->Set_min_price(mem_class_statics[j]->Get_min_price());
				mem_class_p[i]->Set_ave_price(int(mem_class_statics[j]->Get_ave_price()));
				mem_class_p[i]->Set_ndata(mem_class_statics[j]->Get_ndata());
			}
		}
	}
}

void CProducer::Set_qmaxmax(int qmaxmax1,int qmaxmin1,double min_q_init1)
{
	int i,j;
	int crr;
	int qmax;
	double min_q_init;
	qmaxmax=qmaxmax1;
	qmaxmin=qmaxmin1;
	min_q_init=min_q_init1;
	for(i=0;i<ncr_p;i++)
	{
		mem_class_p[i]->Set_qmax(qmaxmax);//qmaxmax=50
		qmax=mem_class_p[i]->Get_qmax();
		crr=cr->strand(qmaxmin,qmax);//qmaxmin=25
//		printf("%d %d %d,%.1f crr=%d\n",qmax,qmaxmin,qmaxmax,min_q_init,crr);
		mem_class_p[i]->Set_q(crr);
		mem_class_p[i]->Set_q_init(crr);
		mem_class_p[i]->Set_q_limit(mem_class_p[i]->Get_q_init());//q_init��q_limit�Ƃ���
		j=int(mem_class_p[i]->Get_q_init()*min_q_init);//min_q_init=0.5
		mem_class_p[i]->Set_q_limit_d(j);
	}
}
void CProducer::Def_qmax()
{
	//���Y�҂̊e���i��ʂ̍ő吶�Y��qmax�̐ݒ�
	int i;
	int crr;
	//qmax�̐ݒ�
	for(i=0;i<ncr_p;i++)
	{
		
		crr=cr->strand(int(0.5*qmaxmax),qmaxmax);
		mem_class_p[i]->Set_qmax(crr);
	}
}
void CProducer::Def_koteihi(int min_koteihi,int max_koteihi)
{
	koteihi=cr->strand(min_koteihi,max_koteihi);
//check
}
void CProducer::Def_hendouhi(int min_hendouhi,int max_hendouhi)
{
	//���Y�҂̊e���i��ʂ�1���i������̐������� hendouhi �̐ݒ�
	int i;
	int crr;
	//qmax�̐ݒ�
	for(i=0;i<ncr_p;i++){
		crr=cr->strand(min_hendouhi,max_hendouhi);
		mem_class_p[i]->Set_hendouhi(0);//�ϓ���=0

	}	
}


void CProducer::Seisan_plan_revised(double q_limit_k,double price_increase_rate,double max_q_re,double min_q_re,double Adjustment_Sensitivity)
{
	//���Y�v��𗧂Ă�
	//���Y���鐻�i��ʖ��ɐ��Y�ʁA���i�����肷��
	//���͉��i�͍l���Ȃ�
	//���Y���鐻�i��ʂ̐��Fncr_p
	int i;
	int nstock;
	int q0,sumq=0;
	int sum=0;
	int sum_q_limit=0;

	//���Y�ʂ����肷��
	for(i=0;i<ncr_p;i++)
	{
		nstock=mem_class_p[i]->Get_nstock();
		q0=Def_q_remodeling(i,max_q_re,min_q_re,Adjustment_Sensitivity);
		if(q0<int(mem_class_p[i]->Get_q_limit()*0.7))	q0=int(mem_class_p[i]->Get_q_limit()*0.7);	//���Y�ʉ����@��{�F0.7
//		printf("ncr_p=%d nstock=%d q0=%d i=%d max_q_re=%.2f min_q_re=%.2f Adjustment_Sensitivity=%.2f \n",ncr_p,nstock,q0,i,max_q_re,min_q_re,Adjustment_Sensitivity);
		if(nstock>0)
		{
			if(q0>nstock) 
			{
				mem_class_p[i]->Set_q(q0-nstock);
				mem_class_p[i]->Flag_down();
			}
			else 
			{
				mem_class_p[i]->Set_q(0);
				mem_class_p[i]->Flag_down();//f_down++;
				mem_class_p[i]->Flag_down();
			}
		}
		else 
		{
			mem_class_p[i]->Set_q(q0);
			mem_class_p[i]->Flag_up();//f_up++;
		}
	}



	int kotei_w,q_lim=0;
	int class_q=0;
	for(i=0;i<ncr_p;i++)
	{
		q_lim+=int(mem_class_p[i]->Get_q_limit()*q_limit_k);
		sumq+=mem_class_p[i]->Get_q();
	}
	nop_sum=sumq;
	
	if(sumq>0)	kotei_w=int(Get_total_price_genka()/sumq+1.0);
	else kotei_w=0;
//	printf("kotei=%d qlim=%d kotei_w=%d const=%d\n",koteihi,q_lim,kotei_w,Get_total_price_genka());
	for(i=0;i<ncr_p;i++)
	{
			cost=kotei_w;
			mem_class_p[i]->Set_price_genka(cost);	
			sum_q_limit+=mem_class_p[i]->Get_q_limit();
	}


	for(i=0;i<ncr_p;i++)
	{
		class_q=0;
		class_q=mem_class_p[i]->Get_q();
		if(class_q!=0)
		{
			mem_class_p[i]->Set_koatari_genryouhi(min_genka_whole+Get_constant_wage()/sum_q_limit);
			printf("min_genka_whole %d\n",min_genka_whole);
		}
		else
		{
			mem_class_p[i]->Set_koatari_genryouhi(min_genka_whole+Get_constant_wage()/sum_q_limit);
		}
	}

}
void CProducer::Seisan_plan_revised(vector <CProduct *>mem_product_whole,double max_q_re,double min_q_re,double Adjustment_Sensitivity)
{
	//���Y�v��𗧂Ă�
	//���Y���鐻�i��ʂ̐��Fncr_p
	int i;
	int nstock;
	int q0,sumq=0;
	int sum=0;

	for(i=0;i<int(mem_employ_const_wage.size());i++)
	{
		sum+=mem_employ_const_wage[i];
	}
	total_constant_wage=sum;//�]�ƈ��̌Œ苋�^�̑��z
	fprintf(cpara->FI_Get_employ_file(),"ag=%d , aaaaaaaaaaaemploy_ size %d , sum=%d \n",Get_Agent_no(),mem_employ_const_wage.size(),total_constant_wage);
	Set_total_constant_wage(total_constant_wage);
	Set_total_price_genka(total_constant_wage);



	//���Y�ʂ����肷��
	

	for(i=0;i<int(mem_class_p.size());i++)
	{
		
		nstock=mem_class_p[i]->Get_nstock();
		q0=Def_q_remodeling(i,max_q_re,min_q_re,Adjustment_Sensitivity);//q0=ave+1.65sigma�Ƃ���Bave=1���Y�҂�����̕��ϔ̔���
		if(q0<int(mem_class_p[i]->Get_q_limit()*0.7))	q0=int(mem_class_p[i]->Get_q_limit()*0.7);

		if(nstock>0)
		{
			if(q0>nstock) 
			{
				mem_class_p[i]->Set_q(q0-nstock);
				mem_class_p[i]->Set_material_need(q0-nstock);
				mem_class_p[i]->Flag_down();//f_down++;���i�t���O��������
			}
			else 
			{
				mem_class_p[i]->Set_q(0);
				mem_class_p[i]->Set_material_need(0);
				mem_class_p[i]->Flag_down();//���i�t���O��������
				mem_class_p[i]->Flag_down();//�啝�ɏd�v���������̂��߉��i�t���O��2�{������
				mem_class_p[i]->Set_bankrup();
			}
		}
		else if(mem_class_p[i]->Get_last_buy_number()>0) //�݌ɂȂ�
		{
			mem_class_p[i]->Set_q(q0);
			mem_class_p[i]->Set_material_need(q0);
			mem_class_p[i]->Flag_up();//���i�t���O���㏸������
			mem_class_p[i]->Set_bankrup_d();
		}
		else
		{
			mem_class_p[i]->Set_q(5);
			mem_class_p[i]->Set_material_need(5);
			mem_class_p[i]->Flag_down();//���i�t���O���㏸������
			mem_class_p[i]->Set_bankrup();
			mem_class_p[i]->Set_bankrup();
		}
		if(Get_Agent_no()==12)	fprintf(cpara->FI_Get_se_income_new(),"no=%d , class_no=%d , buy=%d , q=%d , banker=%d\n",Get_Agent_no(),mem_class_p[i]->Get_class_no(),mem_class_p[i]->Get_last_buy_number(),mem_class_p[i]->Get_q(),mem_class_p[i]->Get_bankrup());
	}

}

int CProducer::Def_q(int i)
{
	int j;
	int nstock;
	j=i;
	int ndata;//�w�����ꂽncr_p_i�Ԗڐ��i��ʏ��i�̎s��S�̂̐�
	int ndata_stock;//����c���Ă���ncr_p_i�Ԗڐ��i��ʏ��i�̎s��S�̂̐�
	int q_re;
	ndata=mem_class_p[j]->Get_ndata();
	nstock=Get_nstock(j);
	ndata_stock=mem_class_p[j]->Get_ndata_stock();
	adj_sens=2;

	if(ndata_stock==0)
	{
		q_re=int(mem_class_p[j]->Get_q()+adj_sens);
	}
	else
	{
		if(nstock==0){q_re=mem_class_p[j]->Get_q();}
		else
		{
			q_re=int(mem_class_p[j]->Get_q()-adj_sens);
			
			if(q_re<0)
			{
				//���Y�����O�ƂȂ�A���Y���~�t���O�𗧂Ă�ꍇ�͂�����
				q_re=0;
			}
		}
	}
	return q_re;
	
}

int CProducer::Def_q_remodeling(int i,double max_q_re,double min_q_re,double Adjustment_Sensitivity)
{
	//�����̐��Y�ʂ����肵�ĕԂ�
	double beta=0.9;
	int j;
	int nstock;
	j=i;
	int ndata;//�w�����ꂽncr_p_i�Ԗڐ��i��ʏ��i�̎s��S�̂̐�
	int ndata_stock;//����c���Ă���ncr_p_i�Ԗڐ��i��ʏ��i�̎s��S�̂̐�
	int q_re;//revised amount of production amount
	
	ndata=mem_class_p[j]->Get_ndata();
	nstock=Get_nstock(j);
	ndata_stock=mem_class_p[j]->Get_ndata_stock();
//	printf("%.2f,%.2f,%.1f\n",max_q_re,min_q_re,Adjustment_Sensitivity);
	adj_sens=Adjustment_Sensitivity;//�������x
	fprintf(cpara->FI_Get_free_text2(),"agent: %d , ",Get_Agent_no());
	q_re=mem_class_p[j]->Safe_q()+mem_class_p[j]->Expectation();

	
	fprintf(cpara->FI_Get_free_text2(),"bf_q_re:%d , exped:%d , ",q_re,mem_class_p[j]->Expectation());
			//Safe_q()//���S�݌ɐ��i����Ԃ� 1.65sigma
			//Expectation();1���Y�҂�����̕��ϔ̔���
		if((nstock==0)&&(q_re>0))
		{
			q_re=int(q_re*max_q_re);
		}
		else
		{
			q_re=int(q_re*min_q_re);
			mem_class_p[j]->Set_eqw(-1);
			if(q_re<int(mem_class_p[j]->Get_q_limit()*beta))
			{
				//���Y�����O�ƂȂ�A���Y���~�t���O�𗧂Ă�ꍇ�͂�����
				mem_class_p[j]->Set_eqw(-1);
			}
		}
		
		if(q_re>mem_class_p[j]->Get_q_limit())
		{
			fprintf(cpara->FI_Get_free_text2(),"q_re:%d , limit:%d",q_re,mem_class_p[j]->Get_q_limit());
			//���Y�������Y���E�𒴂���A�ݔ������t���O�𗧂Ă�ꍇ�͍�����
			q_re=mem_class_p[j]->Get_q_limit();
			mem_class_p[j]->Set_eqw(1);//eqw:�ݔ������v���t���O
		}fprintf(cpara->FI_Get_free_text2(),"\n");
	return q_re;
}

void CProducer::Deliv_material(CProduct * cp)
{

	mem_bought_p.push_back(cp);

}

void CProducer::Calc_cost(double q_limit_k,double p_in_rate,double min_p,double max_p,double min_m,double max_m)
{
	//�e���i��ʖ��ɉ��艿�i���`����price���X�V����
	int hendouhi;
	int i,j;
	int size_wp;
	int sumq=0,q_lim=0;
	int class_q=0;
	int kotei_w;
	int limit_roumuhi=0;				//���i����p�ŏ��J����
	int limit_produce_no=0;			//���i����p�@�ő吶�Y�e��
	double limit_rate=1;			//���i����p�@�ő吶�Y�e�ʂ̉������ɂ��邩�̌���W��
	int no;//���Y���鐔
	int size;
	int sum_q_limit=0;
	size=mem_employ.size();
	int roumuhi=0;

	for(i=0;i<size;i++)
	{
		roumuhi+=mem_employ_const_wage[i];
	}

	for(i=0;i<int(mem_class_p.size());i++)	sum_q_limit+=mem_class_p[i]->Get_q_limit();
	//�ϓ���̌v�Z
	size_wp=mem_bought_p.size();
	for(i=0;i<ncr_p;i++)
	{
		hendouhi=0;
		class_q=0;
		for(j=0;j<size_wp;j++)
		{
			if(mem_class_p[i]->Get_material_no()==mem_bought_p[j]->Get_class_no())
			{
				hendouhi+=mem_bought_p[j]->Get_price();
				sumq++;
				q_lim++;
				class_q++;
			}
		}
		if(class_q!=0)
		{
			mem_class_p[i]->Set_hendouhi(hendouhi);
			mem_class_p[i]->Set_koatari_genryouhi(int(hendouhi/class_q)+Get_constant_wage()/sum_q_limit);
		}
		else
		{
			mem_class_p[i]->Set_hendouhi(hendouhi);
			mem_class_p[i]->Set_koatari_genryouhi(0);
		}
		
	}





	if(sumq>0)
	{
		kotei_w=int(roumuhi/q_lim+1.0);	
		size_wp=mem_bought_p.size();
		for(i=0;i<ncr_p;i++)
		{
			no=0;		
			for(j=0;j<size_wp;j++)
			{
				if(mem_class_p[i]->Get_q()==0)
				{
					no=0;		
				}
				if(mem_bought_p[j]->Get_class_no()==mem_class_p[i]->Get_material_no())
				{
					no++;
				}
			}
			if(no>0)
			{	
				cost=kotei_w+(mem_class_p[i]->Get_hendouhi()/no);
				mem_class_p[i]->Set_price_genka(cost);
//				printf("q_lim=%d , genka=%d , kotei_w=%d , sum=%d  sumq=%d\n",q_lim,mem_class_p[i]->Get_price_genka(),kotei_w,kotei_w*sumq,sumq);
			}
		}
	}


	//�ŏ������v�Z�@���i����p
	for(i=0;i<ncr_p;i++)
	{
		limit_produce_no+=mem_class_p[i]->Get_q_limit();
	}
	limit_roumuhi=int(roumuhi/limit_produce_no*limit_rate);

	for(i=0;i<int(mem_class_p.size());i++)	mem_class_p[i]->Set_limit_genka(limit_roumuhi);
	//�ŏ������v�Z�@�I��

}
void CProducer::Seisan_plan_w(int min_price_w,int max_price_w)
{
	//���Y�v��𗧂Ă�
	//���Y���鐻�i��ʖ��ɉ��i�����肷��
	//���͉��i�͍l���Ȃ�
	//���Y���鐻�i��ʂ̐��Fncr_p
	int i;
	int price;
	int price_genka;
	int sum_price=0;
	int sumq;
	//���Y�ʂ����肷��
	//���Y�ʂ�Set_qmaxmax�Őݒ肵�Ă���B�����͍ő吶�Y��q=q_limit
	//���Y�R�X�g���v�Z����
	//����ҋ��^�̌v�Z
	int size;
	size=mem_employ.size();
	int sum=0;
	int q0;

	//���Y�ʌ���
	for(i=0;i<ncr_p;i++)
	{
			q0=mem_class_p[i]->Get_q_limit();
			mem_class_p[i]->Set_q(q0);
			mem_class_p[i]->Set_koatari_genryouhi(min_genka_whole);
	}
	//���Y�ʌ���I��

	for(i=0;i<size;i++)
	{
		sum+=mem_employ_const_wage[i];
	}
	total_constant_wage=sum;//�]�ƈ��̌Œ苋�^�̑��z
	Set_total_constant_wage(total_constant_wage);
	Set_total_price_genka(total_constant_wage);
		sumq=0;
	for(i=0;i<ncr_p;i++)
	{
		sumq+=mem_class_p[i]->Get_q();
	}
	Set_sum_q(sumq);
	//���i�����肷��
	alpha=9.0;
	for(i=0;i<ncr_p;i++){
		if(sumq!=0) price_genka=int(Get_total_price_genka()/sumq+1.0);
		else price_genka=0;
		mem_class_p[i]->Set_price_genka(price_genka);//���i�P������̌���
		Set_price_genka(price_genka);
		price=int(price_genka*alpha);
		mem_class_p[i]->Set_price(price);
		sum_price=price_genka*sumq;
		fprintf(cpara->FI_Get_seisan(),"W price_genka=%d price=%d sumq=%d q=%d sum_price_genka=%d total_price_genka=%d\n",price_genka,price,sumq,mem_class_p[i]->Get_q(),sum_price,Get_total_price_genka());
	}
	Set_sum_price_genka(sum_price);
}
void CProducer::Seisan_plan(double price_k,int first_price)
{
	//���Y�v��𗧂Ă�
	//���Y���鐻�i��ʖ��ɐ��Y�ʁA���i�����肷��
	//���͉��i�͍l���Ȃ�
	//���Y���鐻�i��ʂ̐��Fncr_p
	int i;
	int price;
	int price_genka;
	int sum_price=0;
	int sumq;
	int size;
	size=mem_employ.size();
	int sum=0;

	for(i=0;i<size;i++)
	{
		sum+=mem_employ_const_wage[i];
	}
	total_constant_wage=sum;//�]�ƈ��̌Œ苋�^�̑��z
	Set_total_constant_wage(total_constant_wage);
	Set_total_price_genka(Get_total_price_genka()+total_constant_wage);
	//���Y�R�X�g���v�Z����
	sumq=0;
	for(i=0;i<ncr_p;i++)
	{
		mem_class_p[i]->Set_q(Get_retail_buy(i));
		sumq+=mem_class_p[i]->Get_q();
	}
	//���i�����肷��
	alpha=price_k;//=3

	for(i=0;i<ncr_p;i++){
		if(sumq!=0){
			price_genka=int((Get_total_price_genka()/sumq)+1.0);
		}
		else price_genka=0;
		Set_price_genka(price_genka);
		price=int(price_genka*1.2);
		if(price_genka < first_price) price=int(first_price*cr->sdrand(0.95,1.05));
		mem_class_p[i]->Set_price(price);
		mem_class_p[i]->Set_price_genka(price_genka);//���i�P������̌���
		mem_class_p[i]->Set_koatari_genryouhi(price_genka);
		sum_price=price_genka*sumq;
		fprintf(cpara->FI_Get_seisan()," price_genka=%d price=%d sumq=%d ncr_p=%d q=%d sum_price_genka=%d�@total_price_genka=%d\n",price_genka,price,sumq,ncr_p,mem_class_p[i]->Get_q(),sum_price,Get_total_price_genka());
	}
	Set_sum_price_genka(sum_price);
}
void CProducer::Set_material_no(vector <int> mem_ncr_w)
{
	//���i��ʖ���mem_ncr_w�̒����猴�����P�������_���Ɏw�肷��B
	int i,j;
	int ncount;
	int size;
	int crr;
	int size_ncr;
	size_ncr=mem_ncr_w.size();
	size=mem_ncr_p.size();
	if(size!=0)
	{
		for(i=0;i<size;i++) mem_ncr_p.pop_back();
	}
	for(i=0;i<ncr_p;i++)
	{
		size=mem_ncr_p.size();
		ncount=0;
restart:
		crr=cr->strand(0,size_ncr-1);
		//���������łȂ����Ƃ��m�F�����������Ȃ琶�����Ȃ����B
		for(j=0;j<size;j++){
			if(mem_ncr_w[crr]==mem_ncr_p[j] && ncount<1000) {
				ncount++;
				goto restart;
			}
		}
		mem_ncr_p.push_back(mem_ncr_w[crr]);
		mem_class_p[i]->Set_material_no(mem_ncr_w[crr]);
		if(i==ncr_p-1)
		{
			for(j=0;j<int(mem_ncr_p.size());j++){}
		}
	}

}
void CProducer::Set_class_no_p(vector <int> mem_ncr_r)
{
	//���Y��ʏW��mem_ncr_p���`����
	int i,j;
	int ncount;
	int size;
	int crr;
	int size_ncr;
	size_ncr=mem_ncr_r.size();
	size=mem_ncr_p.size();
	if(size!=0)
	{
		for(i=0;i<size;i++) mem_ncr_p.pop_back();
	}
	for(i=0;i<ncr_p;i++)
	{
		size=mem_ncr_p.size();
		ncount=0;
restart:
		crr=cr->strand(0,size_ncr-1);
		//���������łȂ����Ƃ��m�F�����������Ȃ琶�����Ȃ����B
		for(j=0;j<size;j++){
			if(mem_ncr_r[crr]==mem_ncr_p[j] && ncount<1000) {
				ncount++;
				goto restart;
			}
		}
		mem_ncr_p.push_back(mem_ncr_r[crr]);
		mem_class_p[i]->Set_class_no(mem_ncr_r[crr]);
		if(i==ncr_p-1)
		{
			for(j=0;j<int(mem_ncr_p.size());j++){}
		}
	}

}
void CProducer::Set_class_no_p(vector <int> mem_ncr_r,vector <int> mem_ncr_r_m)
{
	//���Y��ʏW��mem_ncr_p���`����
	int i,j;
	int ncount;
	int size;
	int crr;
	int size_ncr;
	size_ncr=mem_ncr_r.size();
	size=mem_ncr_p.size();
	if(size!=0)
	{
		for(i=0;i<size;i++) mem_ncr_p.pop_back();
	}
	for(i=0;i<ncr_p;i++)
	{
		size=mem_ncr_p.size();
		ncount=0;
restart:
		crr=cr->strand(0,size_ncr-1);
		//���������łȂ����Ƃ��m�F�����������Ȃ琶�����Ȃ����B
		for(j=0;j<size;j++){
			if(mem_ncr_r[crr]==mem_ncr_p[j] && ncount<1000) {
				ncount++;
				goto restart;
			}
		}
		mem_ncr_p.push_back(mem_ncr_r[crr]);
		mem_class_p[i]->Set_class_no(mem_ncr_r[crr]);
		if(i==ncr_p-1)
		{
			for(j=0;j<int(mem_ncr_p.size());j++){}
		}
	}

	//�����̐ݒ�
	for(i=0;i<int(mem_class_p.size());i++)
	{
		for(j=0;j<int(mem_ncr_r.size());j++)
		{
			if(mem_class_p[i]->Get_class_no()==mem_ncr_r[j])	
			{
				mem_class_p[i]->Set_material_no(mem_ncr_r_m[j]);
			}
		}

	}



}
void CProducer::Set_class_no_p()
{
	//ncr_p�̐��i��ʃC���X�^���X�ɐ��i��ʔԍ����������(���Y���鐻�i��ʁj
	int i,j;
	int ncount;
	int size;
	int crr;
	size=mem_ncr_p.size();
	if(size!=0){
		for(i=0;i<size;i++) mem_ncr_p.pop_back();
	}
	for(i=0;i<ncr_p;i++){
		size=mem_ncr_p.size();

		ncount=0;
restart:
		if(cpara->GET_PARA_n_class()<=12){
			crr=cr->strand(1,int(n_class/2));
		}else{
			crr=cr->strand(1,n_class);
		}
		//���������łȂ����Ƃ��m�F�����������Ȃ琶�����Ȃ����B
		for(j=0;j<size;j++){
			if(crr==mem_ncr_p[j] && ncount<1000) {
				ncount++;
				goto restart;
			}
		}
		mem_ncr_p.push_back(crr);
		mem_class_p[i]->Set_class_no(crr);
		if(i==ncr_p-1){
			for(j=0;j<int(mem_ncr_p.size());j++){}
		}
	}
//	printf("no %d\n",Get_Agent_no());
}
int CProducer::Get_q(int i)
{
	return mem_class_p[i]->Get_q();
}
int CProducer::Set_class_no_p(int count)
{
	//ncr_p�̐��i��ʃC���X�^���X�ɐ��i��ʔԍ����������(���Y���鐻�i��ʁj
	int i,j;
	int ncount;
	int size;
	int crr;
	size=mem_ncr_p.size();
	if(size!=0){
		for(i=0;i<size;i++) mem_ncr_p.pop_back();
	}

	for(i=0;i<ncr_p;i++)
	{
		size=mem_ncr_p.size();

		ncount=0;
		crr=count;
		count++;
		if(count>n_class/2-1) count=0;

		mem_ncr_p.push_back(crr);
		mem_class_p[i]->Set_class_no(crr);
	}
	return count;
}


void CProducer::Set_n_class(int n_class1)
{
	n_class=n_class1;
	//class_no=new int[n_class];//���Y���鐻�i��ʔԍ�
}
void CProducer::Create_Product_class_p(int max_memo_time,int max_reac_flag)
{
	rieki=0;
	//ncr_p��Product_class�̃C���X�^���X�𐶐�����
	int i;
	for(i=0;i<ncr_p;i++){
		pc=new CProduct_class;
		//pc->Set_class_no(cr->strand(1,10));
		pc->Set_Producer_no(Get_Producer_no());
		pc->Set_Agent_no(Get_Agent_no());
		pc->Set_Producer_type(Get_Producer_type());
		pc->Set_ncr_p(ncr_p);
		pc->Set_out(cpara->FI_Get_out());
		pc->Set_test(cpara->FI_Get_test());
		pc->Set_IC(max_memo_time,max_reac_flag,e_flag);
		pc->Set_randum(cr);
		pc->Set_parameter_class(cpara);
		mem_class_p.push_back(pc);

	}
}
void CProducer::Seisan()
{
	//�������Y��
	int i;
//	printf("ncr=%d\n",ncr_p);
	for(i=0;i<ncr_p;i++)
	{
		mem_class_p[i]->Create_product();
		//���i��q���Y����CProduct_class��mem_seihin�Ɋi�[����
		//���i�A�����A�����ԍ��w��ς�
		//�����Ɏd����������B�Œ��ƕϓ���̕��͂ǂ�����Agent�̎����ɐU�蕪����B
	}
}

void CProducer::Seisan_revised()
{
	//�����ȍ~���Y
	int i,j;
	int size_wp;
	int x;
	int no;
	int q;
	vector <CProduct *>::iterator del_wp;
	fprintf(cpara->FI_Get_retai()," , pron= %d\n",Producer_no);
	for(i=0;i<ncr_p;i++)
	{
		x=0;
		no=0;
		q=mem_class_p[i]->Get_q();
		fprintf(cpara->FI_Get_retai()," , class=%d , q=%d , ",mem_class_p[i]->Get_class_no(),q);
		mem_class_p[i]->Erase_mem_seihin();
restart:
		del_wp=mem_bought_p.begin();//�w�����������W���̐擪
		size_wp=mem_bought_p.size();
//		printf("%d\n",size_wp);
		for(j=0;j<size_wp;j++)
		{
			if(q==0)
			{
				break;
			}
			if(mem_bought_p[j]->Get_class_no()==mem_class_p[i]->Get_material_no())
			{
				//�w�������̐��i��ʔԍ����A���Y���鐻�i��ʂɑ΂��ė\�肵�Ă��錴���̎�ʔԍ��ƈ�v���Ă���΁A���̕��������Y����
				mem_bought_p.erase(del_wp);
				mem_class_p[i]->Create_product_revised(x);
						//product�I�u�W�F�N�g�𐶐����ĕK�v�ȏ��i���i���܂ށj��Y�t���Ă��̐��i��ʂ�mem_seihin�ɓ����
				no++;
				q--;
				goto restart;
			}
			del_wp++;
			x++;
		}
	//	printf("%d\n",no);
		fprintf(cpara->FI_Get_retai(),"no=%d\n",no);
		mem_class_p[i]->Set_nop(no);
	}
	nop_sum=0;
	for(i=0;i<ncr_p;i++)
	{
		nop_sum+=mem_class_p[i]->Get_nop();
	}
}
void CProducer::Set_shiwake_hozyokin(int i_period,int hozyokin)
{
	cac.Set_shiwake(i_period,hozyokin,"����","�⏕��","�⏕��",hozyokin,0,3);
}





class CRetailer : public CProducer
{
	int price_w;	int genka;	int loan;	int loan_l;
	int sum_price_genka;

//�`�`�`�`�N���X��ʃN���X�Ƀx�N�^�[�œn�������̎�����	int test_val;


public:



	void Set_total_genka(){sum_price_genka=0;};
	void Set_shiwake_l_hensai(int i_period,int loan_l);
	void Set_shiwake_s_hensai(int i_period,int loan_s);
	void Set_shiwake_uriage(int i_period,int buy_c,int genka);
	void Set_shiwake_yokin_hikidashi(int i_period,int depo_m);
	void Set_shiwake_loan(int i_period,int loan);
	void Set_shiwake_loan_l(int i_period,int loan_l);
	void Set_shiwake_kyuyo(int i_period,int new_income);
	void Set_shiwake_yokin_azuke(int i_period,int b_m);
//	void Set_shiwake_setubi(int i_period,int pro_price,int loan_l);
	void Set_shiwake_konyu(int i_period,int price_w);
	void Set_shiwake_seisan(int i_period,int genka);
	void Set_shiwake_seisan_k(int i_period,int p_gen,int pay_b,int price_w);
	void Set_shiwake_shihon(int i_period,int genkin,int yokin);
	void Set_shiwake_loan_s_hensai(int i_period,int loan_s,int loan_r);
	void Set_shiwake_kimatu(int i_period,int shoukyaku,int loan_l,int loan_r2);
	template<class T,class U> int Decide_buy_material_product_no(T &tag, U &mem_product,int need_class_no,int i_period);

//�`�`�`�`�N���X��ʃN���X�Ƀx�N�^�[�œn�������̎�����
//	void Set_test_val(int x){test_val=x;};
//	int Get_test_val(){return test_val;};
//�`�`�`�`�N���X��ʃN���X�Ƀx�N�^�[�œn�������̎�����
	
};

void CRetailer::Set_shiwake_l_hensai(int i_period,int loan_l)
{
	cac.Set_shiwake(i_period,loan_l,"�����ؓ���","�|�Y���ؓ��ԍ�","�a��",loan_l,2,0);
}
void CRetailer::Set_shiwake_s_hensai(int i_period,int loan_s)
{
	cac.Set_shiwake(i_period,loan_s,"�Z���ؓ���","�|�Y���ؓ��ԍ�","�a��",loan_s,2,0);
}
void CRetailer::Set_shiwake_uriage(int i_period,int buy_c,int genka)
{
	cac.Set_shiwake(i_period,genka,"���㌴��","���i�̔�","���i",genka,1,0);
 	sum_price_genka+=genka;
	cac.Set_shiwake(i_period,buy_c,"����","���i�̔�","����z",buy_c,0,3);
}
void CRetailer::Set_shiwake_yokin_hikidashi(int i_period,int depo_m)
{
	cac.Set_shiwake(i_period,depo_m,"����","�a�����o","�a��",depo_m,0,0);
}
void CRetailer::Set_shiwake_loan(int i_period,int loan)
{
	cac.Set_shiwake(i_period,loan,"�a��","�Z���ؓ�","�Z���ؓ���",loan,0,2);
}
void CRetailer::Set_shiwake_loan_l(int i_period,int loan_l)
{
	cac.Set_shiwake(i_period,loan_l,"����","�����ؓ�","�����ؓ���",loan_l,0,2);
}
void CRetailer::Set_shiwake_kyuyo(int i_period,int new_income)
{
	cac.Set_shiwake(i_period,new_income,"������p","���^�x��","����",new_income,2,0);
}
void CRetailer::Set_shiwake_yokin_azuke(int i_period,int b_m)
{
	cac.Set_shiwake(i_period,b_m,"�a��","�a���a��","����",b_m,0,0);
}
void CRetailer::Set_shiwake_konyu(int i_period,int price_w)
{
	cac.Set_shiwake(i_period,price_w,"����","�����w��","����",price_w,0,0);
}
void CRetailer::Set_shiwake_seisan_k(int i_period,int p_gen,int pay_b,int price_w)
{
	CProducer::Set_shiwake_seisan_k(i_period,p_gen);
	cac.Set_shiwake(i_period,price_w,"���ޗ���","���i���Y","����",price_w,1,0);
	cac.Set_shiwake(i_period,price_w,"���㌴��","���i���Y","���ޗ���",price_w,1,1);
}
void CRetailer::Set_shiwake_seisan(int i_period,int genka)
{
	cac.Set_shiwake(i_period,genka,"���i","���i���Y","���㌴��",genka,0,1);
}
void CRetailer::Set_shiwake_shihon(int i_period,int genkin,int yokin)
{
	cac.Set_shiwake(i_period,genkin,"����","�����ێ���","���厑�{",genkin,0,2);
	cac.Set_shiwake(i_period,yokin,"�a��","�����ێ���","���厑�{",yokin,0,2);
}
void CRetailer::Set_shiwake_loan_s_hensai(int i_period,int loan_s,int loan_r)
{
	cac.Set_shiwake(i_period,loan_s,"�Z���ؓ���","�ԍϏ���","�a��",loan_s,2,0);
	cac.Set_shiwake(i_period,loan_r,"�x������","�ԍϏ���","�a��",loan_r,1,0);
}
void CRetailer::Set_shiwake_kimatu(int i_period,int shoukyaku,int loan_l,int loan_r2)
{
	cac.Set_shiwake(i_period,shoukyaku,"�������p��","��������","�ݔ�",shoukyaku,1,0);
	cac.Set_shiwake(i_period,loan_l,"�����ؓ���","��������","�a��",loan_l,2,0);
	cac.Set_shiwake(i_period,loan_r2,"�x������","��������","�a��",loan_r2,1,0);
}


template<class T,class U> int CRetailer::Decide_buy_material_product_no(T &tag, U &mem_product,int need_class_no,int i_period)
{
	int i,price,checker=0,tag_no=-1,no,checker_2=0;
	for(i=0;i<int(tag.size());i++)		
	{
		if(need_class_no==tag[i]->Get_class_no() && tag[i]->Get_presence_of_stock()==1)
		{
			if(checker==0) 	
			{
				price=tag[i]->Get_price();
				tag_no=i;
				checker=1;
			}
			if(price>tag[i]->Get_price())	
			{
				price=tag[i]->Get_price();
				tag_no=i;
			}
		}
	}

	if(tag_no>-1)
	{
		for(i=0;i<int(mem_product.size());i++)
		{
			if(mem_product[i]->Get_Producer_no()==tag[tag_no]->Get_Producer_no() && mem_product[i]->Get_class_no()==tag[tag_no]->Get_class_no())
			{
				no=i;
				checker_2=1;
				break;
			}
		}
	}
	if(checker_2==0)	no=-1;

	return no;
}







class CWholesaler : public CProducer
{
	int p_gen;	int loan;	int loan_l;
	int total_price_genka;
public:
	void Set_total_genka(){total_price_genka=0;};
	void Set_shiwake_uriage(int i_period,int p_gen,int buy_c);
	void Set_shiwake_yokin_hikidashi(int i_period,int depo_m);
	void Set_shiwake_loan(int i_period,int loan);
	void Set_shiwake_loan_l(int i_period,int loan_l);
	void Set_shiwake_kyuyo(int i_period,int new_income);
	void Set_shiwake_yokin_azuke(int i_period,int b_m);
	void Set_shiwake_seisan_k(int i_period,int p_gen,int pay_b);
	void Set_shiwake_seisan(int i_period,int p_gen);
	void Set_shiwake_shihon(int i_period,int genkin,int yokin);
	void Set_shiwake_loan_s_hensai(int i_period,int loan_s,int loan_r);
	void Set_shiwake_kimatu(int i_period,int shoukyaku,int loan_l,int loan_r2);
	void Set_shiwake_genka_yose(int i_period,int p_gen);
};

void CWholesaler::Set_shiwake_uriage(int i_period,int p_gen,int buy_c)
{
	cac.Set_shiwake(i_period,p_gen,"���㌴��","���i�̔�","���i",p_gen,1,0);
	cac.Set_shiwake(i_period,buy_c,"����","���i�̔�","����z",buy_c,0,3);
	fprintf(cpara->FI_Get_seihin_price(),"%d , %d , %d\n", i_period,Get_Agent_no(),p_gen);
}
void CWholesaler::Set_shiwake_yokin_hikidashi(int i_period,int depo_m)
{
	cac.Set_shiwake(i_period,depo_m,"����","�a�����o","�a��",depo_m,0,0);
}
void CWholesaler::Set_shiwake_loan(int i_period,int loan)
{
	cac.Set_shiwake(i_period,loan,"�a��","�Z���ؓ�","�Z���ؓ���",loan,0,2);
}
void CWholesaler::Set_shiwake_loan_l(int i_period,int loan_l)
{
	cac.Set_shiwake(i_period,loan_l,"����","�����ؓ�","�����ؓ���",loan_l,0,2);
}
void CWholesaler::Set_shiwake_kyuyo(int i_period,int new_income)
{
	cac.Set_shiwake(i_period,new_income,"������p","���^�x��","����",new_income,2,0);
}
void CWholesaler::Set_shiwake_yokin_azuke(int i_period,int b_m)
{
	cac.Set_shiwake(i_period,b_m,"�a��","�a������","����",b_m,0,0);
}
void CWholesaler::Set_shiwake_seisan_k(int i_period,int p_gen,int pay_b)
{
	CProducer::Set_shiwake_seisan_k(i_period,p_gen);
}
void CWholesaler::Set_shiwake_seisan(int i_period,int p_gen)
{
	cac.Set_shiwake(i_period,p_gen,"���i","�������Y","���㌴��",p_gen,0,1);
}
void CWholesaler::Set_shiwake_genka_yose(int i_period,int p_gen)
{
	cac.Set_shiwake(i_period,p_gen,"���㌴��","�������Y","���i",p_gen,0,1);
}
void CWholesaler::Set_shiwake_shihon(int i_period,int genkin,int yokin)
{
	cac.Set_shiwake(i_period,genkin,"����","�����ێ���","���厑�{",genkin,0,2);
	cac.Set_shiwake(i_period,yokin,"�a��","�����ێ���","���厑�{",yokin,0,2);
}
void CWholesaler::Set_shiwake_loan_s_hensai(int i_period,int loan_s,int loan_r)
{
	cac.Set_shiwake(i_period,loan_s,"�Z���ؓ���","�ԍϏ���","�a��",loan_s,2,0);
	cac.Set_shiwake(i_period,loan_r,"�x������","�ԍϏ���","�a��",loan_r,1,0);
}
void CWholesaler::Set_shiwake_kimatu(int i_period,int shoukyaku,int loan_l,int loan_r2)
{
	cac.Set_shiwake(i_period,shoukyaku,"�������p��","��������","�ݔ�",shoukyaku,1,0);
	cac.Set_shiwake(i_period,loan_l,"�����ؓ���","��������","�a��",loan_l,2,0);
	cac.Set_shiwake(i_period,loan_r2,"�x������","��������","�a��",loan_r2,1,0);
}

#endif