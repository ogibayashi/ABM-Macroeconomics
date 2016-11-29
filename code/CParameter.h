
//CParameter.h
//�p�����[�^�A�o�̓t�@�C���̕ϊ��p�F.



#ifndef INC_CPARAMETER
#define INC_CPARAMETER
#include <stdio.h>
#include <vector>
using namespace std;

class CParameter
{
	int Agent_type;
			//Agent_type=10; ��ʏ����
			//Agent_type=20; ��ʏ���Ҍ������Y��
			//Agent_type=30; ���Y�Ҍ������Y�ҁi�����𐶎Y)
			//Agent_type=40; ���Y�Ҍ������Y�ҁi�ݔ����g�[)
			//Agent_type=50; ��s
			//Agent_type=99999;	���{
	int nconsumer;		//��ʏ���҂̐�
	int nretailer;		//��ʏ���Ҍ������Y��
	int nwholesaler;	//���Y�Ҍ������Y�ҁi�����𐶎Y����)
	int nequipment;		//�ݔ������Ґ�
	int nbank;			//��s��

	int n_retailer_worker;		//���e�C���[��Г�����J���Ґ�
	int n_whole_worker;			//�z�[���Z���[��Г�����J���Ґ�
	int n_equip_worker;			//�ݔ�������Г�����J���Ґ�
	int n_bank_worker;			//��s��Г�����J���Ґ�
	int n_government_worker;		//�s���̘J���Ґ�
	int n_max_employee;			//��Г�����̌ٗp����l��

	int n_class;		//�s��ɂ��鐻�i��ʂ̍ő吔
						//���i��ʔԍ���1����n_class�̐�
	int nmax_p;			//�e���Y�҂����Y���鐻�i��ʂ̍ő吔
	int nmax_p_min;
	int nmax_c;			//�e����҂��w�����鐻�i��ʂ̍ő吔
	int qmaxmax;		//���Y�҂̐��Y�\�͂̍ő�l
	int qmaxmin;		//���Y�҂̐��Y�\�͂̍ŏ��l
	int qmaxmax_w;		//�z�[���Z���[�̐��Y�\�͂̍ő�l
	int qmaxmin_w;		//�z�[���Z���[�̐��Y�\�͂̍ŏ��l

	int cob_alpha_r_up;		//�R�u�_�O���X�̐��Y�֐��̌W���A���̏��
	int cob_alpha_r_down;	//�R�u�_�O���X�̐��Y�֐��̌W���A���̉���
	int cob_alpha_w_up;		//�R�u�_�O���X�̐��Y�֐��̌W���A���̏��
	int cob_alpha_w_down;	//�R�u�_�O���X�̐��Y�֐��̌W���A���̉���
	double price_up_rate;	//���i�̏㏸����
	double price_down_rate;	//���i�̉��~����
	double price_change_upper_rate;	//�}���i�K�^�ōŏ��ɔ��l�̍ō����i��X�ɉ��i�����킹��ۂ�X

	int pricing_switch;		//CProducer::new_set_price�ŗp���鉿�i���胋�[���̃X�C�b�`
							//4�F�����^�A5�F�����^_�ϓ������O�����Œ�A6�F�����^
	int bonus_rule_switch;	//CMaket::kessan_agent�ŗp����{�[�i�X���胋�[���̃X�C�b�`
	int buy_producer_switch;//CMarket::buy_producer�ŗp����w�����[���̃X�C�b�`
	int syotokuzei_switch;	//CTax::calc_syotoku_tax�ŗp���鏊���ł̌Œ�ŗ����ݐi�ېł��̃X�C�b�`

	int period_max;			//����
	double depo_rate_c;		//����Ғ��~��
	double depo_rate_p;		//���Y�Ғ��~��
	int nbonus;			//nbonus=0 when without bonus
						//nbonus=1 half bonus
						//nbonus=2 when with bonus
	double bonus_rate_min;	double bonus_rate_max;			//�{�[�i�X��
	double bonus_rate_min_e;	double bonus_rate_max_e;	//�ݔ������{�[�i�X��
	int min_constant_wage;	int max_constant_wage;			//�Œ苋��
	int min_init_depo_c;		int max_init_depo_c;		int min_init_depo_w;		int max_init_depo_w;
	int min_init_depo_r;		int max_init_depo_r;		int min_init_depo_e;		int max_init_depo_e;
	long long min_bank_capital;		long long max_bank_capital;		//�e�G�[�W�F���g�̏�����s�a��

	double min_with_drawal_rate;	double max_with_drawal_rate;//��s�a�����o�z�W��
	int repay_period;//�ԍϊ���
	double capa_increase_rate;	int invest_money;			//�ő吶�Y�ʑ�������//�����K�v���z
	int min_koteihi;int max_koteihi;	int min_hendouhi;	int max_hendouhi;//�Œ�//�ϓ��
	int min_price_w;	int max_price_w; //Whole�̉��i��
	int max_ban;//�ő�p�Ǝw��
	int max_e_flag;//�ő�ݔ������t���O
	int max_equip_end;//�ő�ݔ��ϋv
	int max_memo_time;//����s���L������
	int max_reac_flag;//�݌ɒ����t���O
	int repay_time_ave,repay_time_bun;//�x�������ԁA���K���z���͐��l
	double bank_increase_rate;//����
	double min_price_p;	double max_price_p;	double min_price_m;	double max_price_m;//���i���蕝
	double Adjustment_Sensitivity;//�������x
	double max_q_re;	double min_q_re;//���Y��E�����W��
	double min_q_init;//�������Y����
	double q_limit_k;
	double price_increase_rate;
	int min_q_limit;//���Y�����W��
	double price_k;//���i=����*price_k
	double reserve_rate;//��������
	int ncase;//ncase=0:�����茳����out3�ւ̃v�����g�A�E�g
			  //ncase!=0:�����茳�����v�����g�A�E�g���Ȃ�
	int nkessan;//nkessan=0�Fout3�ւ̃v�����g�A�E�g
				//nkessan=1�Fout3�ւ̕����I�v�����g�A�E�g
				//nkessan!=0or1:out3�ւ̃v�����g�A�E�g�����Ȃ�

	int equip_end;//�ݔ��ϋv
	int invest_max;//��������ݔ��������
	int nbank_con;//��s�]�ƈ�
	int first_price;//���e�C���[���i�������i
	int loan_time_limit;//�Z���ؓ���A���ōs�����Ƃ̂ł�������i����𒴂����ꍇ�͎ؓ�����߂Ĉ�l���فj

	int genkin_kisyu_zandaka; int yokin_kisyu_zandaka;	int loan_kisyu_zandaka;

	int profit_under_line;		//���v�̉����l�i�����ł����肷��Ƃ��ɗ��p����j


	double income_tax_rate;		//������
	double sales_tax_rate;		//�����
	double corp_tax_rate;		//�@�l�ŗ�
	double wage_yosan_rate;		//���{���^�\�Z�� 

	double gov_invest_ratio;	//���{������
	double hosyou_ratio;		//���Ǝҕ⏞��
	double yugu_ratio;			//�������D����
	double kigyou_hozyokin_ratio;	//��ƕ⏕������
	double g_koubai_ratio;		//���{�w������

	int threshold_deposit;		//���~������p�ϐ��A���~�J�n���^�z��臒l
	double deporate_coefficient;	//���~������p�ϐ��A���~������W��c
	int min_genka_whole;		//�z�[���Z���[�p�̍ŏ��ϓ���
	int government_price_rate;	//���{���w������Ƃ��̉��i�̔{�� 
	int buy_producer_amount;	//��Ɠ��m�̍w�����Œ萔�w���ɂ����Ƃ��̍w����
	double gav_wage_rate;			//�s������҂̋��^���x���@1�Ȃ畽�ςƓ��l1�ȉ��Ȃ畽�ψȉ��A1�ȏ�Ȃ畽�ψȏ�

	int CR_fixed_q_limit_up;			//C-R�p�A���^�Œ萶�Y����̗����ݒ莞�̏���l
	int CR_fixed_q_limit_down;			//C-R�p�A���^�Œ萶�Y����̗����ݒ莞�̉����l
	int CR_fixed_income;				//C-R�p�A���^�Œ苋�^
	int CR_limit_genka_up;				//C-R�p�A���^�Œ茴��_�����ݒ���
	int CR_limit_genka_down;			//C-R�p�A���^�Œ茴��_�����ݒ艺��
	int CR_kurikosi_switch;				//C-R�p�A����҂̎����J�z�L������switch
	int CR_q_limit_down_line_switch;	//C-R�p�A���Y�v�掞�̐��Y�ʉ����l��on,offswitch
	int CR_maxqre_decision_switch;		//C-R�p�A���Y�ʉ������̕ω����@�̌�����@switch 0:�����ɑS�����l�ŌŒ�A1:�����ɃG�[�W�F���g���ɗ����ŌŒ�A2:���i���莞�ɗ����ŌŒ�
	int CR_stock_decision_switch;		//C-R�p�A���Y�ʂ̈ӎv���胂�f���̌���switch 0:max_q_re,min_q_re�g�p�@1:�i�؂ꋖ�e�̍݌Ƀ��f���̂ݗ��p

	double Labor_limit_up_basis;		//�����E�ٗp���̗\�z���v/���厑�{�̔��f��̌W��
	int Labor_limit_up_decision_switch;	//�O�F���v�\�����}�C�i�X�Ȃ琶�Y�g�債�Ȃ�����
										//�P�F�\�z���v/���厑�{��Labor_limit_up_basis�ȉ��Ȃ琶�Y�g�債�Ȃ�����
										//�Q�F�\�z���v/"����"���厑�{��Labor_limit_up_basis�ȉ��Ȃ琶�Y�g�債�Ȃ�����

	int Labor_salary_change_switch;		//�O�F�Œ苋��ω������Ȃ�
										//�P�F�Œ苋��ω�������

	int Labor_limit_up_type_switch;		//�O�F���f��@�����	&�@�g����@�@�ݔ��̂݁@�i��ESSA���[���j
										//�P�F���f��@������@	&�@�g����@�@�ݔ��ƌٗp�@�`�`�`����͌��ݗ��p�s�`�`�`
										//�Q�F���f��@���v		&�@�g����@�@�ݔ��̂�
										//�R�F���f��@���v		&�@�g���@�@�ݔ��ٗp
	
	double Labor_situgyouhosyou_rate;	//���ƕۏ�ɗ��p����W��

	int Labor_choice_office_switch;		//�O�F���l�[����ӎv����A�Œ苋�����z
										//�P�F���v��]��������

	int Labor_invest_capital_switch;	//�O�F�ݔ������̍ۂɎ��Ȏ����𗘗p���Ȃ�
										//�P�F�`�`�`������͌��ݎg�p�s�`�`�`�ݔ������̍ۂɎ��Ȏ����𗘗p����
										//�Q�F�ݔ������̍ۂɎ��Ȏ����𗘗p����

	double Labor_invest_capital_rate;	//�ݔ������̍ۂɎ��Ȏ����𗘗p����ꍇ�̗��p����

	int Labor_hozyokin_switch;		//�O�F��ƕ⏕�����ϓ��z��
									//�P�F�N�ƕ⏕���𔄏�ʔz��
									//�Q�F���25%�����ɔ���ʔz��

	double after_tax_rate;			//�V�~�����[�V�������ɕύX����ŗ�
	int after_e_flag;				//�V�~�����[�V�������ɕύX����ݔ������t���O
	int seed;						//�����V�[�h
	double housyu_rate;				//������V����

	int change_time;				//�V�~�����[�V�������Őŗ��Ɛ��Y�g��t���O��ύX����ꍇ�̕ύX����	
	int tax_change_switch;			//�V�~�����[�V�������Őŗ��Ɛ��Y�g��t���O��ύX���邩�̃X�C�b�`
									//�O�F�ύX���s��Ȃ�
									//�P�F�����ł�ύX����
									//�Q�F�@�l�ł�ύX����
	int calc_gdp_switch;			//�O�F��ƊԎ����GDP�Ɋ܂܂Ȃ�
									//�P�F��ƊԎ����GDP�Ɋ܂�

	double R_koubai_yosan_rate;		//��Ƃ̃��e�C���[���i�i���z�Œ莑�{�j�w���\�Z�����@���v�Ōv�Z����ꍇ�j

	int Labor_recognition_riekiritu_switch;	//�O�F���������v���v���ɂ���Đ��Y�g��t���O��ύX���Ȃ�
											//�P�F���������v���v���ɂ���Đ��Y�g��t���O��ύX����
	double Labor_riekiritu;			//���Y�g��t���O�𑝉�������ۂ̏���ӎv���藘�v��

	int Labor_assignment_switch;			//�O�F���{���w���A�⏕���Ɏw���݂��Ȃ�
										//�P�F���{���w���A�⏕���Ɏw���݂���
	int Labor_assignment_size;			//���{�w��̊�Ɛ��i�Ώۊ�Ƃ��炵���w�����Ȃ��j
	
	int Labor_R_buy_profit_switch;	//�O�F��Ɗԍw�����v�ˑ����ibuy_producer_switch=4,14)(�ň��㗘�v-������V)*R_koubai_yosan_rate
									//�P�F��Ɗԍw�����v�ˑ����ibuy_producer_switch=4,14)(�ň���]-������V)*R_koubai_yosan_rate

	int Inv_invest_time;			//�ݔ������i�����ؓ��j�̌��E��

	int Keynes_a;					//�P�C���Y�̏���֐��i�����z�ݒ�j��a

	double owncash_rate_inv;	//�����̍ۂ̎��Ȏ��{���p��
	
	int delta_G;			//20150417 ���{�\�Z�̃�������
	int delta_period_start;	//20150417 ���{�\�Z�̃������J�n��
	int delta_period_end;	//20150417 ���{�\�Z�̃������I����
	double DeltaPurchaseRatio;		//20150601 ���{�\�Z�̃��������̎s��w����
	double DeltaSubsidyRatio;		//20150601 ���{�\�Z�̃��������̊�ƕ⏕��



	/////////////�v�Z���ʏ������ݗp�t�@�C���̐錾//////////////////
	FILE *OUTPUT_GDP;
	FILE *OUTPUT_Deposit;


	FILE *out;	FILE *out1;	FILE *out2;	FILE *test;	FILE *test2;	FILE *test3;	FILE *test4;
 	FILE *product_price;	FILE *product_price_w;	FILE *market_product;	FILE *se_income;
 	FILE *se_con;	FILE *product_out;	FILE *bank_data;
	FILE *economy;	FILE *bought_pro;	FILE *retai;
	FILE *Consumer;   FILE *Retailer;	FILE *Wholesaler;	FILE *Equipment;	FILE *Bank;
    FILE *producer_no;	FILE *se_income_new;	FILE *invest;   FILE *bought_money;	FILE *tax;
	FILE *employ_file;	FILE *seisan;	FILE *agent_no; FILE *kyuyo; FILE *market_data;
	FILE *eqw;

	FILE *shiwake;	FILE *out3;	FILE *out3_csv;	FILE *loan;
	FILE *GDP; FILE *seihin_price;
	FILE *zyunkanhyou; FILE *zyunkandata;
	FILE *parameter;
	FILE *ac_data1; FILE *ac_data2;
	FILE *show_tax;
	FILE *gyousei_syouhisya;
	FILE *producer_data;
	FILE *producer_uriage_kyuyo;
	FILE *producer_uriage;

	FILE *phenom_writer;
	FILE *free_text;
	FILE *price_check;
	FILE *price_check_w;
	FILE *free_text2;
	FILE *rieki_out;
	FILE *loan_out;
	FILE *deposit_out;
	FILE *number_employee;
	FILE *personal_income;
	FILE *corp_capital;
	FILE *seisan_class_no;
	FILE *seisan_class_no_w;

	FILE *consumer_asset;
	FILE *producer_asset;
	FILE *toukei;
	FILE *lorenz;
	FILE *employ;
	FILE *producer_equipment_level;
	FILE *producer_labor_cost;
	FILE *producer_seisan_amount;
	FILE *producer_genryo_price;
	FILE *producer_genryo_no;
	FILE *employ_producer_asset_C;
	FILE *employ_producer_asset_R;
	FILE *statistic_product;
	FILE *CR_product_relation;		//���i��Ɗ�ƁA���i�Ə���҂̊֌W
	FILE *CR_syubetu_koubaimae_seihinsu;
	FILE *CR_syubetu_seisansu;
	FILE *Labor_writer;
	FILE *Labor_employ_time;
	FILE *Labor_parameter_fixed_wage;
	FILE *Labor_kigyouhozyo;
	FILE *Producer_Genkin_suitoutyou;
	FILE *all_money;
	FILE *free_text3;
	FILE *touki_zyunrieki;
	FILE *Labor_housyu_out;
	FILE *Labor_retailer_uriage_rank;
	FILE *Labor_koteishihon;
	FILE *Labor_keihi_soukei;
	FILE *Labor_keihi_toukisonekiritu;

	FILE *Tyotikuritu_pro;
	FILE *Tyotikuritu_uriage_rieki;
	FILE *Tyotikuritu_consumer;
	FILE *Delta_G_writing;

///////////////////�p�����[�^���͗p�t�@�C���錾//////////////////////

	FILE *Experimental_file;	FILE *Other_file;	FILE *Initial_file;	FILE *Variable_file;	FILE *Parameter_FILE_5;
	FILE *Parameter_FILE_6;	FILE *Parameter_FILE_7;	FILE *Parameter_FILE_8;	FILE *Parameter_FILE_9;	

public:
	void FILE_set_parameter();
	void FILE_set_printfile();

	//�p�����[�^�o��GET�֐�
	int GET_PARA_n_retailer_worker(){return n_retailer_worker;};
	int GET_PARA_n_whole_worker(){return n_whole_worker;};
	int GET_PARA_n_equip_worker(){return n_equip_worker;};
	int GET_PARA_n_bank_worker(){return n_bank_worker;};
	int GET_PARA_n_government_worker(){return n_government_worker;};
	double	GET_PARA_Adjustment_Sensitivity(){return Adjustment_Sensitivity;};
	double	GET_PARA_bank_increase_rate(){return bank_increase_rate;};
	double	GET_PARA_bonus_rate_max(){return bonus_rate_max;};
	double	GET_PARA_bonus_rate_min(){return bonus_rate_min;};
	double  GET_PARA_bonus_rate_max_e(){return bonus_rate_max_e;};
	double  GET_PARA_bonus_rate_min_e(){return bonus_rate_min_e;};
	double	GET_PARA_capa_increase_rate(){return capa_increase_rate;};
	double	GET_PARA_corp_tax_rate(){return corp_tax_rate;};
	double	GET_PARA_depo_rate_c(){return depo_rate_c;};
	double	GET_PARA_depo_rate_p(){return depo_rate_p;};
	int	GET_PARA_first_price(){return first_price;};
	double	GET_PARA_income_tax_rate(){return income_tax_rate;};
	int	GET_PARA_invest_money(){return invest_money;};
	int GET_PARA_invest_max(){return invest_max;};
	int	GET_PARA_max_ban(){return max_ban;};
	long long	GET_PARA_max_bank_capital(){return max_bank_capital;};
	int	GET_PARA_max_constant_wage(){return max_constant_wage;};
	int	GET_PARA_max_e_flag(){return max_e_flag;};
	int	GET_PARA_max_equip_end(){return max_equip_end;};
	int	GET_PARA_max_hendouhi(){return max_hendouhi;};
	int	GET_PARA_max_init_depo_c(){return max_init_depo_c;};
	int	GET_PARA_max_init_depo_e(){return max_init_depo_e;};
	int	GET_PARA_max_init_depo_r(){return max_init_depo_r;};
	int	GET_PARA_max_init_depo_w(){return max_init_depo_w;};
	int	GET_PARA_max_koteihi(){return max_koteihi;};
	int	GET_PARA_max_memo_time(){return max_memo_time;};
	double	GET_PARA_max_price_m(){return max_price_m;};
	double	GET_PARA_max_price_p(){return max_price_p;};
	double	GET_PARA_max_q_re(){return max_q_re;};
	int	GET_PARA_max_reac_flag(){return max_reac_flag;};
	double	GET_PARA_max_with_drawal_rate(){return max_with_drawal_rate;};
	long long	GET_PARA_min_bank_capital(){return min_bank_capital;};
	int	GET_PARA_min_constant_wage(){return min_constant_wage;};
	int	GET_PARA_min_hendouhi(){return min_hendouhi;};
	int	GET_PARA_min_init_depo_c(){return min_init_depo_c;};
	int	GET_PARA_min_init_depo_e(){return min_init_depo_e;};
	int	GET_PARA_min_init_depo_r(){return min_init_depo_r;};
	int	GET_PARA_min_init_depo_w(){return min_init_depo_w;};
	int	GET_PARA_min_koteihi(){return min_koteihi;};
	double	GET_PARA_min_price_m(){return min_price_m;};
	double	GET_PARA_min_price_p(){return min_price_p;};
	double	GET_PARA_min_q_init(){return min_q_init;};
	int	GET_PARA_min_q_limit(){return min_q_limit;};
	double	GET_PARA_min_q_re(){return min_q_re;};
	double	GET_PARA_min_with_drawal_rate(){return min_with_drawal_rate;};
	int	GET_PARA_n_class(){return n_class;};
	int	GET_PARA_nbank(){return nbank;};
	int GET_PARA_nbank_con(){return nbank_con;};
	int	GET_PARA_nbonus(){return nbonus;};
	int GET_PARA_ncase(){return ncase;};
	int	GET_PARA_nconsumer(){return nconsumer;};
	int	GET_PARA_nequipment(){return nequipment;};
	int	GET_PARA_nmax_c(){return nmax_c;};
	int	GET_PARA_nmax_p(){return nmax_p;};
	int	GET_PARA_nmax_p_min(){return nmax_p_min;};
	int GET_PARA_nkessan(){return nkessan;};
	int	GET_PARA_nretailer(){return nretailer;};
	int	GET_PARA_nwholesaler(){return nwholesaler;};
	int	GET_PARA_period_max(){return period_max;};
	double	GET_PARA_price_increase_rate(){return price_increase_rate;};
	double	GET_PARA_price_k(){return price_k;};
	double	GET_PARA_q_limit_k(){return q_limit_k;};
	int	GET_PARA_qmaxmax(){return qmaxmax;};
	int	GET_PARA_qmaxmax_w(){return qmaxmax_w;};
	int	GET_PARA_qmaxmin(){return qmaxmin;};
	int	GET_PARA_qmaxmin_w(){return qmaxmin_w;};
	int	GET_PARA_repay_period(){return repay_period;};
	int	GET_PARA_repay_time_ave(){return repay_time_ave;};
	int	GET_PARA_repay_time_bun(){return repay_time_bun;};
	double	GET_PARA_reserve_rate(){return reserve_rate;};
	double	GET_PARA_sales_tax_rate(){return sales_tax_rate;};
	double GET_PARA_gov_invest_ratio(){return gov_invest_ratio;};
	double GET_PARA_hosyou_ratio(){return hosyou_ratio;};
	double GET_PARA_yugu_ratio(){return yugu_ratio;};
	double GET_PARA_kigyou_hozyokin_ratio(){return kigyou_hozyokin_ratio;};
	double GET_PARA_g_koubai_ratio(){return g_koubai_ratio;};
	int GET_PARA_threshold_deposit(){return threshold_deposit;};
	double GET_PARA_deporate_coefficient(){return deporate_coefficient;};
	int GET_PARA_profit_under_line(){return profit_under_line;};
	int GET_PARA_loan_time_limit(){return loan_time_limit;};
	double GET_PARA_wage_yosan_rate(){return wage_yosan_rate;};
	int GET_PARA_min_genka_whole(){return min_genka_whole;};
	int GET_PARA_cob_alpha_r_up(){return cob_alpha_r_up;};
	int GET_PARA_cob_alpha_r_down(){return cob_alpha_r_down;};
	int GET_PARA_cob_alpha_w_up(){return cob_alpha_w_up;};
	int GET_PARA_cob_alpha_w_down(){return cob_alpha_w_down;};
	int GET_PARA_pricing_switch(){return pricing_switch;};
	double GET_PARA_price_up_rate(){return price_up_rate;};
	double GET_PARA_price_down_rate(){return price_down_rate;};
	double GET_PARA_price_change_upper_rate(){return price_change_upper_rate;};	
	int GET_PARA_bonus_rule_switch(){return bonus_rule_switch;};
	int GET_PARA_buy_producer_switch(){return buy_producer_switch;};
	int GET_PARA_government_price_rate(){return government_price_rate;};
	int GET_PARA_buy_producer_amount(){return buy_producer_amount;};
	int GET_PARA_syotokuzei_switch(){return syotokuzei_switch;};
	double GET_PARA_gav_wage_rate(){return gav_wage_rate;};
	int GET_PARA_max_employee(){return n_max_employee;};

	int GET_PARA_CR_fixed_q_limit_up(){return CR_fixed_q_limit_up;};
	int GET_PARA_CR_fixed_q_limit_down(){return CR_fixed_q_limit_down;};
	int GET_PARA_CR_fixed_income(){return CR_fixed_income;};
	int GET_PARA_CR_limit_genka_up(){return CR_limit_genka_up;};
	int GET_PARA_CR_limit_genka_down(){return CR_limit_genka_down;};
	int GET_PARA_CR_kurikosi_switch(){return CR_kurikosi_switch;};
	int GET_PARA_CR_q_limit_down_line_switch(){return CR_q_limit_down_line_switch;};	
	int GET_PARA_CR_maxqre_decision_switch(){return CR_maxqre_decision_switch;};		
	int GET_PARA_CR_stock_decision_switch(){return CR_stock_decision_switch;};		


	double Get_PARA_Labor_Labor_limit_up_basis(){return Labor_limit_up_basis;};
	int Get_PARA_Labor_limit_up_decision_switch(){return Labor_limit_up_decision_switch;};
	int Get_PARA_Labor_salary_change_switch(){return Labor_salary_change_switch;};
	int Get_PARA_Labor_limit_up_type_switch(){return Labor_limit_up_type_switch;};
	double Get_PARA_Labor_situgyouhosyou_rate(){return Labor_situgyouhosyou_rate;};
	int Get_PARA_Labor_choice_office_switch(){return Labor_choice_office_switch;};
	int Get_PARA_Labor_invest_capital_switch(){return Labor_invest_capital_switch;};
	double Get_PARA_Labor_invest_capital_rate(){return Labor_invest_capital_rate;};
	int Get_PARA_Labor_hozyokin_switch(){return Labor_hozyokin_switch;};

	void change_income_tax_rate(){income_tax_rate=after_tax_rate;};
	void change_corp_tax_rate(){corp_tax_rate=after_tax_rate;};
	void change_e_flag(){max_e_flag=after_e_flag;};
	int Get_PARA_seed(){return seed;};
	double Get_PARA_housyu_rate(){return housyu_rate;};
	int Get_PARA_change_time(){return change_time;};
	int Get_PARA_tax_change_switch(){return tax_change_switch;}
	int Get_PARA_calc_gdp_switch(){return calc_gdp_switch;}
	double Get_PARA_R_koubai_yosan_rate(){return R_koubai_yosan_rate;};

	double Get_PARA_Labor_riekiritu(){return Labor_riekiritu;}
	int Get_PARA_Labor_recognition_riekiritu_switch(){return Labor_recognition_riekiritu_switch;}

	int Get_PARA_Labor_assignment_switch(){return Labor_assignment_switch;};
	int Get_PARA_Labor_assignment_size(){return Labor_assignment_size;};
	int Get_PARA_Labor_R_buy_profit_switch(){return Labor_R_buy_profit_switch;};
	int Get_PARA_Inv_invest_time(){return Inv_invest_time;};
	int Get_PARA_Keynes_a(){return Keynes_a;};
	double Get_PARA_owncash_rate_inv(){return owncash_rate_inv;};

	int Get_Para_delta_G(){return delta_G;}
	int Get_para_delta_period_start(){return	delta_period_start;}
	int Get_para_delta_period_end(){return delta_period_end;}	
	double Get_para_DeltaPurchaseRatio(){return DeltaPurchaseRatio;};
	double Get_para_DeltaSubsidyRatio(){return DeltaSubsidyRatio;}; 



	//�o�͗p�t�@�C���A�h���X�󂯓n���A�h���XGET�֐��Q
	FILE* FI_Get_out(){return out;};
	FILE* FI_Get_out1(){return out1;};
	FILE* FI_Get_out2(){return out2;};
	FILE* FI_Get_test(){return test;};
	FILE* FI_Get_test2(){return test2;};
	FILE* FI_Get_test3(){return test3;};
	FILE* FI_Get_test4(){return test4;};
	FILE* FI_Get_product_price(){return product_price;};
	FILE* FI_Get_product_price_w(){return product_price_w;};
	FILE* FI_Get_market_product(){return market_product;};
	FILE* FI_Get_se_income(){return se_income;};
	FILE* FI_Get_se_con(){return se_con;};
	FILE* FI_Get_product_out(){return product_out;};
	FILE* FI_Get_bank_data(){return bank_data;};
	FILE* FI_Get_economy(){return economy;};
	FILE* FI_Get_bought_pro(){return bought_pro;};
	FILE* FI_Get_retai(){return retai;};
	FILE* FI_Get_Consumer(){return Consumer;};
	FILE* FI_Get_Retailer(){return Retailer;};
	FILE* FI_Get_Wholesaler(){return Wholesaler;};
	FILE* FI_Get_Equipment(){return Equipment;};
	FILE* FI_Get_Bank(){return Bank;};
	FILE* FI_Get_producer_no(){return producer_no;};
	FILE* FI_Get_se_income_new(){return se_income_new;};
	FILE* FI_Get_invest(){return invest;};
	FILE* FI_Get_bought_money(){return bought_money;};
	FILE* FI_Get_tax(){return tax;};
	FILE* FI_Get_employ_file(){return employ_file;};
	FILE* FI_Get_seisan(){return seisan;};
	FILE* FI_Get_agent_no(){return agent_no;};
	FILE* FI_Get_kyuyo(){return kyuyo;};
	FILE* FI_Get_market_data(){return market_data;};
	FILE* FI_Get_eqw(){return eqw;};
	FILE* FI_Get_shiwake(){return shiwake;};
	FILE* FI_Get_out3(){return out3;};
	FILE* FI_Get_out3_csv(){return out3_csv;};
	FILE* FI_Get_loan(){return loan;};
	FILE* FI_Get_GDP(){return GDP;};
	FILE* FI_Get_seihin_price(){return seihin_price;};
	FILE* FI_Get_zyunkanhyou(){return zyunkanhyou;};
	FILE* FI_Get_zyunkandata(){return zyunkandata;};
	FILE* FI_Get_parameter(){return parameter;};
	FILE* FI_Get_ac_data1(){return ac_data1;};
	FILE* FI_Get_ad_data2(){return ac_data2;};
	FILE* FI_Get_show_tax(){return show_tax;};
	FILE* FI_Get_gyousei_syouhisya(){return gyousei_syouhisya;};
	FILE* FI_Get_producer_data(){return producer_data;};
	FILE* FI_Get_producer_uriage_kyuyo(){return producer_uriage_kyuyo;};
	FILE* FI_Get_producer_uriage(){return producer_uriage;};
	FILE* FI_Get_free_text(){return free_text;};
	FILE* FI_Get_phenom_writer(){return phenom_writer;};
	FILE* FI_Get_price_check(){return price_check;};
	FILE* FI_Get_price_check_w(){return price_check_w;};
	FILE* FI_Get_free_text2(){return free_text2;};
	FILE* FI_Get_rieki_out(){return rieki_out;};
	FILE* FI_Get_loan_out(){return loan_out;};
	FILE* FI_Get_deposit_out(){return deposit_out;};
	FILE* FI_Get_number_employee(){return number_employee;};
	FILE* FI_Get_personal_income(){return personal_income;};
	FILE* FI_Get_corp_capital(){return corp_capital;};
	FILE* FI_Get_seisan_class_no(){return seisan_class_no;};
	FILE* FI_Get_seisan_class_no_w(){return seisan_class_no_w;};
	FILE* FI_Get_consumer_asset(){return consumer_asset;};
	FILE* FI_Get_producer_asset(){return producer_asset;};
	FILE* FI_Get_toukei(){return toukei;};
	FILE* FI_Get_lorenz(){return lorenz;};
	FILE* FI_Get_employ(){return employ;};
	FILE* FI_Get_equipment_level(){return producer_equipment_level;};
	FILE* FI_Get_labor_cost(){return producer_labor_cost;};
	FILE* FI_Get_seisan_amount(){return producer_seisan_amount;};
	FILE* FI_Get_genryo_price(){return producer_genryo_price;};
	FILE* FI_Get_genryo_no(){return producer_genryo_no;};
	FILE* FI_Get_employ_producer_asset_C(){return employ_producer_asset_C;};
	FILE* FI_Get_employ_producer_asset_R(){return employ_producer_asset_R;};
	FILE* FI_Get_statistic_product(){return statistic_product;};
	FILE* FI_Get_CR_product_relation(){return CR_product_relation;};
	FILE* FI_Get_CR_syubetu_koubaimae_seihinsu(){return CR_syubetu_koubaimae_seihinsu;};
	FILE* FI_get_CR_syubetu_seisansu(){return CR_syubetu_seisansu;};
	FILE* FI_Get_Labor_writer(){return Labor_writer;};
	FILE* FI_Get_Labor_employ_time(){return Labor_employ_time;};
	FILE* FI_Get_Labor_parameter_fixed_wage(){return Labor_parameter_fixed_wage;};
	FILE* FI_Get_Labor_kigyouhozyo(){return Labor_kigyouhozyo;};
	FILE* FI_Get_Producer_Genkin_suitoutyou(){return Producer_Genkin_suitoutyou;};
	FILE* FI_Get_all_money(){return all_money;};
	FILE* FI_Get_free_text3(){return free_text3;};
	FILE* FI_Get_touki_zyunrieki(){return touki_zyunrieki;};
	FILE* FI_Get_Labor_housyu_out(){return Labor_housyu_out;};
	FILE* FI_Get_Labor_retailer_uriage_rank(){return Labor_retailer_uriage_rank;};
	FILE* FI_Get_Labor_koteishihon(){return Labor_koteishihon;};
	FILE* FI_Get_Labor_keihi_soukei(){return Labor_keihi_soukei;};
	FILE* FI_Get_Labor_keihi_toukisonekiritu(){return Labor_keihi_toukisonekiritu;}
	FILE* FI_Get_Tyotikuritu_pro(){return Tyotikuritu_pro;};
	FILE* FI_Get_Tyotikuritu_uriage_rieki(){return Tyotikuritu_uriage_rieki;};
	FILE* FI_Get_Tyotikuritu_consumer(){return Tyotikuritu_consumer;};

	FILE* FI_Get_Delta_G_writing(){return Delta_G_writing;};

	FILE* FI_GET_OUTPUT_GDP(){return OUTPUT_GDP;};
	FILE* FI_GET_OUTPUT_Deposit(){return OUTPUT_Deposit;};
};

void CParameter::FILE_set_parameter()
{
	
	fopen_s(&Initial_file,"..\\parameter\\01Experimental_file.csv","r");	
	fopen_s(&Experimental_file,"..\\parameter\\02Initial_file.csv","r");
	fopen_s(&Variable_file,"..\\parameter\\03Variable_file.csv","r");
	fopen_s(&Other_file,"..\\parameter\\04Other_file.csv","r");

	fscanf_s(Experimental_file,"%d			,%d			,%d			,%d				,%d			,%d		,%lf					,%lf					,%lf				,%lf			,%lf			,%lf			,%d			,%d			,%d					,%d					,%d					,%lf			,%lf				,%d				,%d				,%d			,%d			,%d			"
							,&period_max	,&nconsumer	,&nretailer	,&nwholesaler	,&nequipment,&nbank	,&min_with_drawal_rate	,&max_with_drawal_rate	,&bank_increase_rate,&bonus_rate_min,&bonus_rate_max,&housyu_rate	,&n_class	,&Keynes_a	,&threshold_deposit	,&min_constant_wage	,&max_constant_wage	,&price_up_rate	,&price_down_rate	,&repay_time_ave,&invest_money	,&max_ban	,&nmax_p	,&nmax_c	);
	
	
	fscanf_s(Initial_file,"%d,%d			,%d						,%d					,%d			,%lf				,%lf"
				,&Inv_invest_time,&max_e_flag	,&delta_period_start	,&delta_period_end	,&delta_G	,&DeltaPurchaseRatio,&DeltaSubsidyRatio);


	fscanf_s(Variable_file,"%d				,%d					,%d					,%d					,%d					,%d					,%d					,%d					,%lld				,%lld"
							,&min_init_depo_c	,&max_init_depo_c	,&min_init_depo_w	,&max_init_depo_w	,&min_init_depo_r	,&max_init_depo_r	,&min_init_depo_e	,&max_init_depo_e	,&min_bank_capital	,&max_bank_capital);


	fscanf_s(Other_file,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,%lf,%d,%lf,%d,%d,%d,%d,%d,%lf,%lf,%d,%d,%d,%d,%d,%lf,%d,%lf,%d,%d,%d,%d,%lf,%d,%lf,%lf,%lf,%lf,%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,%lf,%lf,%d,%lf,%d,%d"
						,&repay_time_bun,&pricing_switch,&buy_producer_switch,&syotokuzei_switch,&ncase,&nkessan,&nbonus,&n_retailer_worker,&n_whole_worker,&n_equip_worker,&n_bank_worker,&n_government_worker,&seed,&qmaxmax,&qmaxmax_w,&qmaxmin,&qmaxmin_w,&min_price_w,&max_price_w,&first_price,&min_koteihi,&max_koteihi,&min_hendouhi,&max_hendouhi,&cob_alpha_r_up,&cob_alpha_r_down	,&cob_alpha_w_up,&cob_alpha_w_down	,&min_q_limit	,&q_limit_k	,&min_q_init,&min_price_p	,&max_price_p	,&min_price_m	,&max_price_m	,&Adjustment_Sensitivity,&max_q_re	,&min_q_re	,&price_increase_rate	,&price_k	,&loan_time_limit	,&min_genka_whole	,&price_change_upper_rate	,&repay_period	,&capa_increase_rate	,&nmax_p_min	,&invest_max	,&max_memo_time	,&max_reac_flag	,&buy_producer_amount	,&reserve_rate	,&Labor_limit_up_basis	,&Labor_limit_up_decision_switch	,&Labor_salary_change_switch	,&Labor_limit_up_type_switch	,&Labor_choice_office_switch	,&Labor_invest_capital_switch	,&Labor_invest_capital_rate	,&Labor_hozyokin_switch	,&after_tax_rate	,&after_e_flag	,&tax_change_switch	,&change_time	,&calc_gdp_switch	,&R_koubai_yosan_rate	,&Labor_R_buy_profit_switch	,&owncash_rate_inv	,&income_tax_rate	,&sales_tax_rate,&corp_tax_rate	,&profit_under_line	,&gov_invest_ratio	,&hosyou_ratio	,&yugu_ratio	,&kigyou_hozyokin_ratio	,&g_koubai_ratio,&wage_yosan_rate	,&government_price_rate	,&gav_wage_rate	,&Labor_situgyouhosyou_rate	,&Labor_recognition_riekiritu_switch	,&Labor_riekiritu	,&Labor_assignment_switch	,&Labor_assignment_size);




	nbank_con=0;
	n_max_employee=0;
	bonus_rule_switch=0;
	bonus_rate_min_e=0;
	bonus_rate_max_e=0;
	deporate_coefficient=0;
	CR_fixed_q_limit_up=0;CR_fixed_q_limit_down=0;CR_fixed_income=0;CR_limit_genka_up=0;CR_limit_genka_down=0;CR_kurikosi_switch=0;
	max_equip_end=0;
	depo_rate_c=0;
	depo_rate_p=0;


	fclose(Experimental_file);	fclose(Other_file);	fclose(Initial_file);	fclose(Variable_file);	
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",nconsumer,nretailer,nwholesaler,nequipment,nbank,n_class,nmax_p,nmax_c,qmaxmax,qmaxmax_w,period_max,nbonus,nmax_p_min);
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",min_constant_wage,max_constant_wage,min_init_depo_c,max_init_depo_c,min_init_depo_w,max_init_depo_w,min_init_depo_r,max_init_depo_r);

	fopen_s(&parameter,"..\\data\\parameter.csv","w");
	fprintf(parameter,"Experimental_file\n");
	fprintf(parameter,"period_max(d),nconsumer(d),nretailer(d),nwholesaler(d),nequipment(d),nbank(d),ncase(d),nkessan(d),nbonus(d),nbank_con(d),n_retailer_worker(d),n_whole_woker(d),n_equip_woker(d),n_bank_woker(d),n_government_woker(d),n_max_employee(d),seed(d)\n");
	fprintf(parameter,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",period_max,nconsumer,nretailer,nwholesaler,nequipment,nbank,ncase,nkessan,nbonus,nbank_con,n_retailer_worker,n_whole_worker,n_equip_worker,n_bank_worker,n_government_worker,n_max_employee,seed);
	
	fprintf(parameter,"Other_file\n");
	fprintf(parameter,"n_class(d),nmax_p(d),nmax_c(d),repay_time_ave(d),repay_time_bun(d),max_ban(d),pricing_switch(d),bonus_rule_switch(d),buy_producer_switch(d),syotokuzei_switch(d)\n");
	fprintf(parameter,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",n_class,nmax_p,nmax_c,repay_time_ave,repay_time_bun,max_ban,pricing_switch,bonus_rule_switch,buy_producer_switch,syotokuzei_switch);

	fprintf(parameter,"Initial_file\n");
	fprintf(parameter,"min_constant_wage(d),max_constant_wage(d),bonus_rate_min(lf),bonus_rate_max(lf),bonus_rate_min_e(lf),bonus_rate_max_e(lf),min_with_drawal_rate(lf),max_with_drawal_rate(lf),threshold_deposit,deporate_coefficient\n");
	fprintf(parameter,"%d,%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,%lf\n",min_constant_wage,max_constant_wage,bonus_rate_min,bonus_rate_max,bonus_rate_min_e,bonus_rate_max_e,min_with_drawal_rate,max_with_drawal_rate,threshold_deposit,deporate_coefficient);
	
	fprintf(parameter,"Variable_file\n");
	fprintf(parameter,"min_init_depo_c(d),max_init_depo_c(d),min_init_depo_w(d),max_init_depo_w(d),min_init_depo_r(d),max_init_depo_r(d),min_init_depo_e(d),max_init_depo_e(d),min_bank_capital(d),max_bank_capital(d)\n");
	fprintf(parameter,"%d,%d,%d,%d,%d,%d,%d,%d,%lld,%lld\n",min_init_depo_c,max_init_depo_c,min_init_depo_w,max_init_depo_w,min_init_depo_r,max_init_depo_r,min_init_depo_e,max_init_depo_e,min_bank_capital,max_bank_capital);
	
	fprintf(parameter,"parameter_FILE_5\n");
	fprintf(parameter,"qmaxmax(d),qmaxmax_w(d),qmaxmin(d),qmaxmin_w(d),min_price_w(d),max_price_w(d),first_price(d),min_koteihi(d),max_koteihi(d),min_hendouhi(d),max_hendouhi(d),cob_alpha_r_up(d),cob_alpha_r_down(d),cob_alpha_w_up(d),cob_alpha_w_down(d)\n");
	fprintf(parameter,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",qmaxmax,qmaxmax_w,qmaxmin,qmaxmin_w,min_price_w,max_price_w,first_price,min_koteihi,max_koteihi,min_hendouhi,max_hendouhi,cob_alpha_r_up,cob_alpha_r_down,cob_alpha_w_up,cob_alpha_w_down);
	
	fprintf(parameter,"parameter_FILE_6\n");
	fprintf(parameter,"min_q_limit(d),q_limit_k(lf),min_q_init(lf),min_price_p(lf),max_price_p(lf),min_price_m(lf),max_price_m(lf),Adjustment Sensitivity(lf),max_q_re(lf),min_q_re(lf),price_increase_rate(lf),price_k(lf),loan_time_limit(d),min_genka_whole(d),price_up_rate(lf),price_down_rate(lf),price_change_upper_rate(lf)\n");
	fprintf(parameter,"%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%d,%d,%lf,%lf,%lf\n",min_q_limit,q_limit_k,min_q_init,min_price_p,max_price_p,min_price_m,max_price_m,Adjustment_Sensitivity,max_q_re,min_q_re,price_increase_rate,price_k,loan_time_limit,min_genka_whole,price_up_rate,price_down_rate,price_change_upper_rate);
	
	fprintf(parameter,"parameter_FILE_7\n");
	fprintf(parameter,"repay_period(d),capa_increase_rate(lf),invest_money(d),nmax_p_min(d),invest_max(d),max_e_flag(d),max_equip_end (d),max_memo_time(d),max_reac_flag(d),buy_producer_amount(d),CR_fixed_q_limit_up(d),CR_fixed_q_limit_down(d),CR_fixed_income(d),CR_limit_genka(d),CR_limit_genka(d),CR_kurikosi_switch(d)\n");
	fprintf(parameter,"%d,%lf,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",repay_period,capa_increase_rate,invest_money,nmax_p_min,invest_max,max_e_flag,max_equip_end,max_memo_time,max_reac_flag,buy_producer_amount,CR_fixed_q_limit_up,CR_fixed_q_limit_down,CR_fixed_income,CR_limit_genka_up,CR_limit_genka_down,CR_kurikosi_switch);
	
	fprintf(parameter,"parameter_FILE_8\n");
	fprintf(parameter,"reserve_rate(lf),bank_increase_rate(lf),depo_rate_c(lf),depo_rate_p(lf),Labor_limit_up_basis(lf),Labor_switchng_limit_up(d),Labor_salary_change_switch(d),Labor_limit_up_type_switch(d),Labor_choice_office_switch(d),Labor_invest_capital_switch(d) , Labor_invest_capital_rate(lf),Labor_hozyokin_switch(d),after_tax_rate(lf),after_e_flag(d),housyu_rate(lf),tax_change_switch(d),&change_time(d),calc_gdp_switc(d),R_koubai_yosan_rate(lf),Labor_R_buy_profit_switch(d),owncash_rate_inv\n");
	fprintf(parameter,"%lf,%lf,%lf,%lf,%lf,%d,%d,%d,%d,%d,%lf,%d,%lf,%d,%lf,%d,%d,%d,%lf,%d,%lf\n",reserve_rate,bank_increase_rate,depo_rate_c,depo_rate_p,Labor_limit_up_basis,Labor_limit_up_decision_switch,Labor_salary_change_switch,Labor_limit_up_type_switch,Labor_choice_office_switch,Labor_invest_capital_switch,Labor_invest_capital_rate,Labor_hozyokin_switch,after_tax_rate,after_e_flag,housyu_rate,tax_change_switch,change_time,calc_gdp_switch,R_koubai_yosan_rate,Labor_R_buy_profit_switch,owncash_rate_inv);
	
	fprintf(parameter,"parameter_FILE_9\n");
	fprintf(parameter,"income_tax_rate (lf),sales_tax_rate (lf),corp_tax_rate(lf),profit_under_line(d),gov_invest_ratio(lf),hosyou_ratio(lf),yugu_ratio(lf),kigyou_hozyokin_ratio(lf),g_koubai_ratio(lf),wage_yosan_rate(lf),government_price_rate(d),gov_wage_rate(lf),Labor_situgyouhosyou_rate(lf),Labor_recognition_riekiritu_switch(d),Labor_riekiritu(lf),Inv_invest_time(d),Keynes_a(d),delta_G,delta_period_start,delta_period_end,DeltaPurchaseRatio,DeltaSubsidyRatio\n");
	fprintf(parameter,"%lf,%lf,%lf,%d,%lf,%lf,%lf,%lf,%lf,%lf,%d,%lf,%lf%d,%lf,%d,%d,%d,%d,%lf,%lf\n",income_tax_rate,sales_tax_rate,corp_tax_rate,profit_under_line,gov_invest_ratio,hosyou_ratio,yugu_ratio,kigyou_hozyokin_ratio,g_koubai_ratio,wage_yosan_rate,government_price_rate,gav_wage_rate,Labor_situgyouhosyou_rate,Labor_recognition_riekiritu_switch,Labor_riekiritu,Labor_assignment_switch,Labor_assignment_size,Inv_invest_time,Keynes_a,delta_G,delta_period_start,delta_period_end,DeltaPurchaseRatio,DeltaSubsidyRatio);
}

void CParameter::FILE_set_printfile()
{
		//////�t�@�C���̃I�[�v��//////////
	fopen_s(&OUTPUT_GDP,"..\\data\\01OUTPUT_GDP.csv","w");
	fopen_s(&OUTPUT_Deposit,"..\\data\\02OUTPUT_Deposit.csv","w");

	fopen_s(&employ_file,"..\\data\\employ.txt","w");
	fopen_s(&out,"..\\data\\out.txt","w");							//�e�G�[�W�F���g�̌ʏ��
	fopen_s(&out1,"..\\data\\out1.txt","w");						//�s��̍w�����i�̐��Y��ʓ��v�f�[�^
	fopen_s(&out2,"..\\data\\retailer_zaiko.csv","w");						//�s��̍݌ɑ���
	fopen_s(&test,"..\\data\\test.txt","w");
	fopen_s(&test2,"..\\data\\product_zaiko.csv","w");
	fopen_s(&test3,"..\\data\\class_price.csv","w");
	fopen_s(&test4,"..\\data\\product_seisan.csv","w");						//���i��ʔԍ��ʂ�max,min,ave
	fopen_s(&product_price,"..\\data\\product_ave_price.csv","w");		//show mem_buy�ŕς�ꂽ���̉��i�W�v
	fopen_s(&product_price_w,"..\\data\\product_ave_price_w.csv","w");	//wholesaler�̍��ڕʉ��i����?
	fopen_s(&market_product,"..\\data\\market_product.csv","w");	//����E�����@���e�C���[���z�[���Z���[����
	fopen_s(&se_income,"..\\data\\se_income.txt","w");				//�eAgent�̋��^
	fopen_s(&se_con,"..\\data\\se_con.txt","w");					//�e����ҕʏ���
	fopen_s(&product_out,"..\\data\\product_out.txt","w");			//�e���e�C���[�̐��i��ʐ��Y��
	fopen_s(&bank_data,"..\\data\\bank_data.txt","w");				//���� �����,���Y��,�a���c��,�ؓ����c��,����җa�����z,��Ɨa�����z,�a�����z,�ؓ������z
	fopen_s(&economy,"..\\data\\economy.txt","w");
	fopen_s(&bought_pro,"..\\data\\bought_pro.txt","w");			//���Y�ҕ� ���i�A�����A���i���A�����A�ő吶�Y�ʁA�������Y��
	fopen_s(&retai,"..\\data\\retai.txt","w");
	fopen_s(&Consumer,"..\\data\\Consumer.txt","w");				//�����
	fopen_s(&Retailer,"..\\data\\Retailer.txt","w");				//���e�C���[
	fopen_s(&Wholesaler,"..\\data\\Wholesaler.txt","w");				//�z�[���Z���[
	fopen_s(&Equipment,"..\\data\\Equipment.txt","w");				//�ݔ����Y
	fopen_s(&Bank,"..\\data\\Bank.txt","w");				//��s
	fopen_s(&producer_no,"..\\data\\producer_no.txt","w");
	fopen_s(&se_income_new,"..\\data\\se_income_new.txt","w");
	fopen_s(&invest,"..\\data\\invest.csv","w");
	fopen_s(&bought_money,"..\\data\\bought_money.csv","w");
	fopen_s(&tax,"..\\data\\tax.txt","w");//�ŋ�
	fopen_s(&seisan,"..\\data\\seisan.txt","w");
	fopen_s(&agent_no,"..\\data\\agent_no.csv","w");//�cAgent��
	fopen_s(&kyuyo,"..\\data\\kyuyo.csv","w");//��ƕʋ��^
	fopen_s(&market_data,"..\\data\\market_data.csv","w");//�s��f�[�^�e��
	fopen_s(&eqw,"..\\data\\eqw.csv","w");//�e��ƕʐ��i��ʐݔ������t���O
	fopen_s(&shiwake,"..\\data\\shiwake.txt","w");	fprintf(shiwake,"Agebt_no , ���� , ���z , �ؕ� , �E�v , �ݕ� , ���z , kari_code , kashi_code\n");
	fopen_s(&out3,"..\\data\\out_genkin.txt","w");
	fopen_s(&out3_csv,"..\\data\\out_genkin.csv","w");
	fopen_s(&loan,"..\\data\\loan.csv","w");
	fopen_s(&GDP,"..\\data\\GDP.csv","w");
	fopen_s(&seihin_price,"..\\data\\seihin_price.csv","w");
	fopen_s(&zyunkanhyou,"..\\data\\zyunkanhyou.csv","w");
	fopen_s(&zyunkandata,"..\\data\\zyunkandata.csv","w");
	fopen_s(&ac_data1,"..\\data\\ac_data1.csv","w");
	fopen_s(&ac_data2,"..\\data\\ac_data2.csv","w");
	fopen_s(&gyousei_syouhisya,"..\\data\\gyousei_syouhisya.csv","w");
	fopen_s(&show_tax,"..\\data\\show_tax.csv","w");
	fopen_s(&producer_data,"..\\data\\producer_data.csv","w");
	fopen_s(&producer_uriage_kyuyo,"..\\data\\producer_uriage_kyuyo.csv","w");
	fopen_s(&producer_uriage,"..\\data\\producer_uriage.csv","w");
	fopen_s(&free_text,"..\\data\\free_text.csv","w");
	fopen_s(&phenom_writer,"..\\data\\phenom_writer.csv","w");
	fopen_s(&price_check,"..\\data\\price_check.csv","w");
	fopen_s(&price_check_w,"..\\data\\price_check_w.csv","w");
	fopen_s(&free_text2,"..\\data\\free_text2.csv","w");
	fopen_s(&rieki_out,"..\\data\\rieki_out.csv","w");
	fopen_s(&loan_out,"..\\data\\loan_out.csv","w");
	fopen_s(&deposit_out,"..\\data\\deposit_out.csv","w");
	fopen_s(&number_employee,"..\\data\\number_employee.csv","w");
	fopen_s(&personal_income,"..\\data\\personal_income.csv","w");
	fopen_s(&corp_capital,"..\\data\\corp_capital.csv","w");
	fopen_s(&seisan_class_no,"..\\data\\seisan_class_no.csv","w");
	fopen_s(&seisan_class_no_w,"..\\data\\seisan_class_no_w.csv","w");
	fopen_s(&consumer_asset,"..\\data\\consumer_asset.csv","w");
	fopen_s(&producer_asset,"..\\data\\producer_asset.csv","w");
	fopen_s(&toukei,"..\\data\\toukei.csv","w");
	fopen_s(&lorenz,"..\\data\\lorenz.csv","w");
	fopen_s(&employ,"..\\data\\employ.csv","w");
	fopen_s(&producer_equipment_level,"..\\data\\producer_equipment_level.csv","w");
	fopen_s(&producer_labor_cost,"..\\data\\producer_labor_cost.csv","w");
	fopen_s(&producer_seisan_amount,"..\\data\\producer_seisan_amount.csv","w");
	fopen_s(&producer_genryo_price,"..\\data\\producer_genryo_price.csv","w");
	fopen_s(&producer_genryo_no,"..\\data\\producer_genryo_no.csv","w");
	fopen_s(&employ_producer_asset_C,"..\\data\\employ_producer_asset_C.csv","w");
	fopen_s(&employ_producer_asset_R,"..\\data\\employ_producer_asset_R.csv","w");
	fopen_s(&statistic_product,"..\\data\\statistic_product.csv","w");
	fopen_s(&CR_product_relation,"..\\data\\CR_product_relation.csv","w");
	fopen_s(&CR_syubetu_koubaimae_seihinsu,"..\\data\\CR_syubetu_koubaimae_seihinsu.csv","w");
	fopen_s(&CR_syubetu_seisansu,"..\\data\\CR_syubetu_seisansu.csv","w");

	fopen_s(&Labor_writer,"..\\data\\Labor_writer.csv","w");
	fopen_s(&Labor_employ_time,"..\\data\\Labor_employ_time.csv","w");
	fopen_s(&Labor_parameter_fixed_wage,"..\\data\\Labor_parameter_fixed_wage.csv","w");
	fopen_s(&Labor_kigyouhozyo,"..\\data\\Labor_kigyouhozyo.csv","w");
	fopen_s(&Producer_Genkin_suitoutyou,"..\\data\\Producer_Genkin_suitoutyou.csv","w");
	fopen_s(&all_money,"..\\data\\all_money.csv","w");
	fopen_s(&free_text3,"..\\data\\free_text3.csv","w");
	fopen_s(&touki_zyunrieki,"..\\data\\touki_zyunrieki.csv","w");
	fopen_s(&Labor_housyu_out,"..\\data\\Labor_housyu_out.csv","w");
	fopen_s(&Labor_retailer_uriage_rank,"..\\data\\Labor_retailer_uriage_rank.csv","w");
	fopen_s(&Labor_koteishihon,"..\\data\\Labor_koteishihon.csv","w");
	fopen_s(&Labor_keihi_soukei,"..\\data\\Labor_keihi_soukei.csv","w");
	fopen_s(&Labor_keihi_toukisonekiritu,"..\\data\\Labor_keihi_toukisonekiritu.csv","w");

	fopen_s(&Tyotikuritu_pro,"..\\data\\tyotikuritu_pro.csv","w");
	fopen_s(&Tyotikuritu_uriage_rieki,"..\\data\\Tyotikuritu_uriage_rieki.csv","w");
	fopen_s(&Tyotikuritu_consumer,"..\\data\\Tyotikuritu_consumer.csv","w");

	fopen_s(&Delta_G_writing,"..\\data\\Delta_G_writing.csv","w");


	


	
	

	////���ʂׂ̈̏����o��/////////
	fprintf(OUTPUT_Deposit,"t,Consumer_Deposit,Producer_Deposit\n");
	fprintf(OUTPUT_GDP,"t,GDP\n");


	fprintf(test3,"����,�N���X�i���o,�}�b�N�X,�~�j,�A�x\n");//file�o��
	fprintf(product_out,"���e�C���[,���i��,���Y��\n");//file�o��
	fprintf(bank_data,"����,�R���V���}�i���o�[,�v���f���[�T�i���o�[,�a���c��,�ؓ����c��,����җa�����z,��Ɨa�����z,�a�����z,�ؓ������z\n");//file�o��
	fprintf(market_product,"����,wh���Y��,wh�w���O���i��,wh�w���㐻�i��,re_���Y��,re_����ҍw���O���i��,re_����ҍw���㐻�i��,incomen,re_���{�w���O���i��,re_���{�w���㐻�i��,re_��ƍw���O���i��,re_��ƍw���㐻�i��\n");//file�o��
	fprintf(se_income,"����,�i���o�[,���^,���e�C���[���v,�ݔ����v,�z�[���Z���[���v,���v\n");//file�o��
	fprintf(producer_no,"����,���e�C����,�z�[���Z���[��\n");
	fprintf(bought_money,"����,bought_sum_r,bought_sum_w,bought_sum\n");
	fprintf(tax,"����,������,��ƕʏ�����,�����ō��v\n");
	fprintf(seisan,"Prodcer_type,Type_no,Producer_no,price_genka,price,sumq,q,ncr_p,sum_price_genka,total_price_genka\n");
	fprintf(agent_no,"����,Consumer,Retailer,Wholesaler,Equipment,Bank,R_employ,W_employ,E_employ,B_employ,Employ\n");
	fprintf(kyuyo,"����,R_���^���v,W_���^���v,E_���^���v,B_���^���v,���^�����v\n");
	fprintf(eqw,"����,��ƕʐ��i��ʐݔ������t���O\n");
	fprintf(GDP,"����,����,�݌�,GDP,����Ҏ��v,���{���v,�ݔ�����,���z�Œ莑�{�`��,�搔\n");
	fprintf(seihin_price,"����,�G�[�W�F���g,�݌�\n");
	fprintf(zyunkandata,"����,r����,r�݌�,r�x������,r����,r�J����,r��ʊǗ���,r�������p��,rr���i�w��,r���t��,r�c�Ɨ]��,w����,w�݌�,w�x�����q,w�J����,w��ʊǗ���,w�������p,wr���i�w��,w���t��,w�c�Ɨ]��,e����,e�x�����q,e�J����,��ʊǗ���,e���t��,e�c�Ɨ]��,b����,b�x������,b�J����,b��ʊǗ���,b���v\n");
	fprintf(gyousei_syouhisya,"����,�Ŏ�,���^�\�Z,�����\�Z,���ƕ⏞�\�Z,���{�����\�Z,�D���\�Z,��ƕ⏕���\�Z,�w���\�Z,���{�w��,�s������҈�l�����苋�^,���ƕۏ��l������x����,���{�����z,�D���⏕,��ƕ⏕��,���{�c��\n");
	fprintf(market_data,"����,����ҋ��^���v,���ԋ��^���v,���������^���v,����Ҍ���,����җa��,r�a��,w�a��,e�a��,��Ɨa�����v,b����,�Z���ؓ�,�����ؓ�,�ؓ����v\n");
	fprintf(show_tax,"����,�@�l��,������,�����,���v\n");
	fprintf(invest,"����,Re_�ݔ�������,Wh_�ݔ�������,Re_�ݔ��������z,Wh_�ݔ��������z\n");
	fprintf(rieki_out,"����,");
	fprintf(loan_out,"����,");
	fprintf(deposit_out,"����,");
	fprintf(product_price,"����,");
	fprintf(product_price_w,"����,");
	fprintf(number_employee,"����,retailer,");
	fprintf(personal_income,"����");
	fprintf(corp_capital,"����");
	fprintf(price_check,"����,");
	fprintf(price_check_w,"����,");
	fprintf(seisan_class_no,"����,");
	fprintf(seisan_class_no_w,"����,");
	fprintf(consumer_asset,"����,");
	fprintf(producer_asset,"����,");
	fprintf(toukei,"����,");
	fprintf(lorenz,"����,,");
	fprintf(producer_uriage,"����,");
	fprintf(employ,"����,");
	fprintf(employ_producer_asset_C,"����,");
	fprintf(employ_producer_asset_R,"����,");
	fprintf(Labor_writer,"�J���E�ݔ������Ɋւ���ӎv����֌W�̋L�q");
	fprintf(Labor_employ_time,"���� , �ٗp�� ,  , �`�`�`�`�e��Ƃ̌ٗp�s���������̊����̉�\n");
	fprintf(Labor_parameter_fixed_wage,"���� , �p�����[�^�Œ苋 , �`�`�`�`����҂���ԕϐ��Ƃ��ČŗL���Ă���Œ苋�̃p�����[�^\n");
	fprintf(Labor_kigyouhozyo,"���� , \n");
	fprintf(all_money,"�^�C�~���O , ���� , ���v , ����Ҍ��� , ����җa�� , R���� , R�a�� , W���� , W�a�� , E���� , E�a�� , B���� , B�a�� , G���� , �����̂ݍ��v , ����+�a���i��s�����j \n");
	fprintf(touki_zyunrieki,"���� , �ň����㏃���v\n");
	fprintf(Labor_housyu_out,"���� \n");
	fprintf(Labor_koteishihon,"���� , ���{�Œ�z\n");
	fprintf(Labor_keihi_soukei,"���� , ");
	fprintf(Labor_keihi_toukisonekiritu,"���� , ");
	fprintf(Tyotikuritu_pro,"���� , ���e�C���[�Ō㗘�v , ���e�C���[��] , ���e�C���[���~�� , �z�[���Z���[�Ō㗘�v , �z�[���Z���[��] , �z�[���Z���[���~�� , �ݔ��Ō㗘�v , �ݔ���] , �ݔ����~�� , ��ƐŌ㗘�v , ��Ə�] , ��ƒ��~��,���e�C���[���~���ő�l , �z�[���Z���[���~���ő�l , �ݔ����~���ő�l\n");
	fprintf(Tyotikuritu_uriage_rieki,"���� , ���e�C���[���� , ���e�C���[�x�o , ���e�C���[���~�� , �z�[���Z���[���� , �z�[���Z���[�x�o , �z�[���Z���[���~�� , �ݔ��Ō㔄�� , �ݔ��x�o , �ݔ����~�� , ��ƐŌ㔄�� , ��Ǝx�o , ��ƒ��~��\n");
	fprintf(Tyotikuritu_consumer,"���� , ���� , �x�o , ���~��\n");

}






#endif