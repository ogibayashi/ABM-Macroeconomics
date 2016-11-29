//CAccount.h
#ifndef INC_CAccount
#define INC_CAccount
#include <stdio.h>
#include <vector>
#include"CParameter.h"
#include"CTax.h"
#include"CRandum.h"
using namespace std;

class CAccount
{
/*	struct debt{
		double i_rate;
		double A;//�����ؓ��z
		double ar
	}*/
	struct shiwake {
		char date[20],karikata[50],tekiyo[50],kashikata[50];
		long long kari,kashi;
		int kari_code,kashi_code;
		int aite_Agent_no;
	}*sh;
	struct kanjyo_kamoku
		{
		char kamoku[50];
		long long karikata_total;
		long long kashikata_total;
		long long zandaka;
		long long kisyu_zandaka;
		long long kimatu_zandaka;
		int code;//=0:���Y�Ȗ�,=1:�o��Ȗ�,=2:���Ȗ�,=3�F����Ȗ�
	}*km,*kmr;
	struct shisan_kamoku
	{
		char kamoku[50];
	}*shisan_km;
	struct keihi_kamoku
	{
		char kamoku[50];
	}*keihi_km;
	struct husai_kamoku
	{
		char kamoku[50];
	}*husai_km;
	struct uriage_kamoku
	{
		char kamoku[50];
	}*uriage_km;
	struct genyokin_suitou			//�����a���o�[������^�@�ꉞ�ۑ�
	{
		int i_period;	//����
		char tekiyou[50];	//�E�v
		char tekiyou_aite[50];	//�E�v�̑���
		char kamoku[50];
		long long kari_yokin;		//�a������
		long long kashi_yokin;	//�a���x�o
		long long yokin_zandaka;	//�a���c��

		long long kari_genkin;	//��������
		long long kashi_genkin;	//�����x�o
		long long genkin_zandaka;	//�a���c��
		int code;			//���a���o�[�R�[�h�@1:��������,2:�����x�o,3:�a������,4:�a���x�o
	}*genyo_suitou;

	struct suitoutyou			//�����A�a���o�[���\���́A���e�͓����Ȃ̂ō\���͓̂���̂��̂��g�p
	{
		int i_period;			//����
		char tekiyou[50];		//�E�v
		char tekiyou_aite[50];	//�E�v����
		char kamoku[50];		//����Ȗ�
		long long kari;				//�ؕ��i�����j
		long long kashi;				//�ݕ��i�x�o�j
		long long zandaka;			//�c��
		int code;				//�����o�[���R�[�h
	}*genkin_suitou,*yokin_suitou;

	struct ather_kamoku			//�ȖڂŊ������Z��������ȃ^�C�~���O�ł̂ݎg�p����f�[�^�ϐ�
	{
		long long zeimae_soneki;		//�ň����O���v
		long long minus_soneki;		//�{�[�i�X�v�Z���ɍs���}�C�i�X�����v�̕�Ă�

		long long touki_zyun_soneki;	//���������v
		long long mibarai_zei;		//�����̎x����ꂽ������
		long long touki_mibarai_zei;	//�����v�Z������
		long long kisyu_mibarai_zei;	//���񖢕���
		long long kimatu_mibarai_zei;	//����������

		long long mibarai_shouhi_zei;			//�����̎x����ꂽ�����������
		long long touki_mibarai_shouhi_zei;	//�����v�Z���������
		long long kisyu_mibarai_shouhi_zei;	//���񖢕��������
		long long kimatu_mibarai_shouhi_zei;	//���������������

		long long rieki_zyouyo;		//���v��]��
		long long kisyu_rieki_zyouyo;	//���񗘉v��]��
		long long kimatu_rieki_zyouyo;//�������v��]��

		long long mibarai_bonus;			//
		long long touki_mibarai_bonus;	//
		long long kisyu_mibarai_bonus;	//
		long long kimatu_mibarai_bonus;	//

		long long mibarai_housyu;
		long long touki_miabrai_housyu;
		long long kisyu_mibarai_housyu;
		long long kiamtu_mibarai_housyu;

	}*at_km;

	struct out_kessan_data		//��p�A���㓙�A���������ŏ�������f�[�^�̕ۊǌ�
	{
		long long genryou_out;	
		long long setubi_out; 
		long long ukerisi_out; 
		long long siharisi_out;
		long long kyuyo_out;		
		long long bonus_out;	
		long long uriage_out;	
		long long rieki_out;
		long long zaiko_zandaka_t_1; 
		long long genkasyoukyaku_out;	
		long long zaiko_out;
		long long kyuyo;
		long long kyuyo_c;
		long long houzin_zei;
		long long syotoku_zei;
		long long yakuin_housyu;
		long long syoumouhin;
		long long kigyou_hozyokin;		//�󂯎���Ƒ��̊�ƕ⏕��
		long long kigyou_hozyokin_g;		//�x�������{���̊�ƕ⏕��
		long long syouhisya_kouhukin;		//�󂯎�����ґ��̌�t��
		long long syouhisya_kouhukin_g;	//�x�������{���̌�t��
		long long touki_zeigo_rieki;
		long long touki_zyunsoneki;
	}*out_data;


	int i_period;
	int Agent_no;
	int ndata;
	int nkamoku;
	int nshisan_kamoku;
	int nkeihi_uriage_kamoku;
	int nkeihi_kamoku;
	int nuriage_kamoku;
	int nhusai_kamoku;
	int loan_point;			//�Z���ؓ������m�F
	long long zeimae_rieki;		//�ň����O���v
	long long touki_soneki;		//�ň����㗘�v�A���������v
	long long pl_rieki;			//
	long long bl_rieki;			//
	long long rieki;
	int agent_type;			//Agent_type=10; ��ʏ����
							//Agent_type=20; ��ʏ���Ҍ������Y��
							//Agent_type=30; ���Y�Ҍ������Y�ҁi�����𐶎Y)
							//Agent_type=40; ���Y�Ҍ������Y�ҁi�ݔ����g�[)
							//Agent_type=50; ��s
							//Agent_type=9999;	���{



	long long genkin_kisyu_zandaka;			long long genkin_kimatu_zandaka;
	long long yokin_kisyu_zandaka;			long long yokin_kimatu_zandaka;
	long long yokin_b_kisyu_zandaka;		long long yokin_b_kimatu_zandaka;
	long long loan_s_kisyu_zandaka;			long long loan_s_kimatu_zandaka;
	long long loan_s_b_kisyu_zandaka;		long long loan_s_b_kimatu_zandaka;
	long long loan_l_kisyu_zandaka;			long long loan_l_kimatu_zandaka;
	long long loan_l_b_kisyu_zandaka;		long long loan_l_b_kimatu_zandaka;
	long long shihon_kisyu_zandaka;			long long shihon_kimatu_zandaka;
	long long mibarai_kisyu_zandaka;		long long mibarai_kimatu_zandaka;
	long long seihin_kisyu_zandaka;			long long seihin_kimatu_zandaka;
	long long genryouhi_kisyu_zandaka;		long long genryouhi_kimatu_zandaka;
	long long setubi_kisyu_zandaka;			long long setubi_kimatu_zandaka;
	long long chingin_kisyu_zandaka;		long long chingin_kimatu_zandaka;
	long long rounuhi_kisyu_zandaka;		long long rounuhi_kimatu_zandaka;
	long long bonus_kisyu_zandaka;			long long bonus_kimatu_zandaka;
	long long kanrihi_kisyu_zandaka;		long long kanrihi_kimatu_zandaka;
	long long uriage_genka_kisyu_zandaka;	long long uriage_genka_kimatu_zandaka;
	long long uriage_kisyu_zandaka;			long long uriage_kimatu_zandaka;
	long long syoukyaku_kisyu_zandaka;		long long syoukyaku_kimatu_zandaka;
	long long kari_risoku_s_kisyu_zandaka;	long long kari_risoku_s_kimatu_zandaka;
	long long kari_risoku_l_kisyu_zandaka;	long long kari_risoku_l_kimatu_zandaka;
	long long bank_risoku_u_kisyu_zandaka;	long long bank_risoku_u_kimatu_zandaka;
	long long genzairyo_kisyu_zandaka;		long long genzairyo_kimatu_zandaka;
	long long kyuyo_kisyu_zandaka;			long long kyuyo_kimatu_zandaka;


	long long kashi_risoku_s_kisyu_zandaka;	long long kashi_risoku_s_kimatu_zandaka;
	long long kashi_risoku_l_kisyu_zandaka;	long long kashi_risoku_l_kimatu_zandaka;
	long long bank_risoku_h_kisyu_zandaka;	long long bank_risoku_h_kimatu_zandaka;
	long long genryou_out;			long long setubi_out;			long long ukerisi_out;	long long siharisi_out;
	long long kyuyo_out;			long long bonus_out;			long long uriage_out;	long long rieki_out;
	long long zaiko_zandaka_t_1;	long long genkasyoukyaku_out;	long long zaiko_out;
	long long kyuyo_c_out;
	long long houzin_zei_out;		//�@�l�ł̊������Z�ۑ��p
	long long syoumouhin_out;		//���Օi�̊������Z�ۑ��p
	long long kigyou_hozyokin_out;//��ƕ⏕���̊������Z�ۑ��p
	long long yakuin_housyu_out;
	long long hozyokin_out;		//�󂯎��⏕���̊������Z�ۑ��p
	long long kouhukin_out;		//����Ҍ�����t���i�D���������Ŏg�p�j�̊������Z�ۑ��p
	long long buy_retailer_product_out;	//��Ƃ̃��e�C�����i�̍w���z
	long long out_touki_zyouyo;
	long long touki_keihi_soukei;		//�����̌o��v


	vector <struct shiwake *> mem_sh;
	vector <struct shisan_kamoku *> mem_shisan_km;
	vector <struct keihi_kamoku *> mem_keihi_km;
	vector <struct husai_kamoku *> mem_husai_km;
	vector <struct uriage_kamoku *> mem_uriage_km;
	vector <struct kanjyo_kamoku *> mem_km;
	vector <struct kanjyo_kamoku *> mem_kmr;
	vector <long long > mem_riekizyouyo;					//�ݐϐԎ������݂���ꍇ�̐ŏ����̂���
//	vector <struct genyokin_suitou *> mem_suitou;	�����a���o�[������^�@�ꉞ�ۑ�
	vector <struct suitoutyou *> mem_genkin_suitou;	//�����o�[���@�\���̂͗a���Ɠ��l�̂��̂��g�p
	vector <struct suitoutyou *> mem_yokin_suitou;	//�a���o�[���@�\���̂͌����Ɠ��l�̂��̂��g�p

	CParameter *cpara;
	CTax *cta;

//	FILE *shiwake;	FILE *out3;	FILE *out3_csv;	FILE *loan;
	FILE *seihin_price;

	FILE *suitoutyou;
	FILE *yokin;
	int nkessan;//nkessan=0�Fout3�ւ̃v�����g�A�E�g
				//nkessan=1�Fout3�ւ̕����I�v�����g�A�E�g
				//nkessan!=0or1:out3�ւ̃v�����g�A�E�g�����Ȃ�
	CRandum *cr;

public:
	CAccount();
	void Set_parameter_class(CParameter * cpar){cpara=cpar;};
	void Set_CTax_class(CTax *ct){cta=ct;};
	void Set_Agent_type(int agtype){agent_type=agtype;};

	__int64 Tyotiku_get_zeigorieki(){return out_data->touki_zeigo_rieki;};
	__int64 tyotiku_get_zyunneki(){return out_data->touki_zyunsoneki;};

	//�o�[��
	void Set_genyokin_suitoutyou(int i_period,char *tekiyou,char *tekiyou_aite,char *kamoku,int amount,int code);
	void Set_genkin_suitoutyou(int i_period,char *tekiyou,char *tekiyou_aite,char *kamoku,long long amount,int code);
	void Set_yokin_suitoutyou(int i_period,char *tekiyou,char *tekiyou_aite,char *kamoku,long long amount,int code);
	void Reset_genyokin_suitoutyou();
	int Get_genkin_suitoutyou_zandaka(){return int(mem_genkin_suitou[mem_genkin_suitou.size()-1]->zandaka);};
	int Get_yokin_suitoutyou_zandaka(){return int(mem_yokin_suitou[mem_yokin_suitou.size()-1]->zandaka);};
//long long�^�Ή�
	__int64 Get_genkin_suitoutyou_zandaka_l(){return mem_genkin_suitou[mem_genkin_suitou.size()-1]->zandaka;};
	__int64 Get_yokin_suitoutyou_zandaka_l(){return mem_yokin_suitou[mem_yokin_suitou.size()-1]->zandaka;};
//�`�`�`�`�`�`�`�`�`�`

	//�o�[���I���

	//���Z�p�֐�
	void Kessan(int i_period,int ncase,FILE *out3,FILE *out3_csv);	//�ȉ��̌��Z�p�֐����Ǘ�����

	void Define_km();		//�ȖڃR�[�h
	void Re_define_km();	//
	void Shisan_table(int i_period,int ncase,FILE *out3,FILE *out3_csv);	//�d���������ׂĉȖڂɐU�蕪��
	void PLsheet_table(FILE *out3,FILE *out3_csv);		//PL�V�[�g�ɕK�v�Ȑ��l���v�Z	�ň����O���v�m��
	void Balance_table(FILE *out3,FILE *out3_csv);		//�o�����X�e�[�u���ɕK�v�Ȑ��l���v�Z�@�ň����O���v�m��
	void Calculation_tax();								//�ŋ��z�̌v�Z�A�����ŋ��v��A�������v�m��
	void Calculation_touki_soneki();					//�����̑��v���v�Z����
	void Soneki_hurikae();								//�������v�����{�ɕғ�����
	void Show_kimatu_zandaka(int x,FILE *out3);			//
	void Convert_kimatu_kisyu();						//�������l�����񐔒l�Ɉڂ��ւ��i�����̍ŏI�����j
	void Loan_s_check();								//�Z���ؓ��̏�ԃ`�F�b�N
	void Erase_mem_sh();								//�d������O�폜

	//���Z�p�֐��I��

	void Print_balance_table(FILE *out3,FILE *out3_csv);//
	void Print_pLsheet_table(FILE *out3,FILE *out3_csv);//


	//�ŋ��֘A
	int Get_mibarai_tax(){return int(at_km->kisyu_mibarai_zei);};
	int Get_mibarai_shouhi_tax(){return int(at_km->kisyu_mibarai_shouhi_zei);};
	void Set_shiharai_tax(int pay_tax){at_km->mibarai_zei=at_km->mibarai_zei-pay_tax;};//printf("�����Ł@�F�@����%d , ����%d , ����%d\n",at_km->kisyu_mibarai_zei,at_km->mibarai_zei,at_km->kisyu_mibarai_zei);};
	void Set_shiharai_bonus(int pay_bonus){at_km->mibarai_bonus=at_km->mibarai_bonus-pay_bonus;};
	void Set_shiharai_shouhi_tax(int pay_tax){at_km->mibarai_shouhi_zei=at_km->mibarai_shouhi_zei-pay_tax;};
	void Calc_bonus();
	void Calc_shouhi_tax();

	//�ŋ��֘A�I��

	//��V�֘A
	int Get_mibarai_housyu(){return int(at_km->kisyu_mibarai_housyu);};
	void Set_shiarai_housyu(int pay_housyu){at_km->mibarai_housyu=at_km->mibarai_housyu-pay_housyu;};
	void Set_mibarai_housyu(int mibarai){at_km->kisyu_mibarai_housyu+=mibarai;};
	void kessan_housyu();
	void calc_housyu();

	//��V�֘A�I��


	void Set_seihin_price(FILE *fi){seihin_price=fi;};
	void Set_nkessan(int nkessan1){nkessan=nkessan1;};	
	int Get_kamoku(int index,char *kamoku);
	long long Get_kamoku_l(int index,char *kamoku);
	void Set_kisyu_re();
	void Set_kimatu_re();
	void Set_Agent_no(int Agent_no1){Agent_no=Agent_no1;};
	void Get_kimatu_zandaka(int *genkin,int *yokin,int *loan_s,int *loan_l,int *shihon,int *mibarai,int *seihin,int *genryouhi,int *setubi);
	int Get_rieki(){return int(at_km->touki_zyun_soneki);};
	void Set_kisyu_zandaka(int genkin,int yokin,int loan_s,int loan_l,int shihon,int mibarai,int seihin,int genryouhi,int setubi);
	void Set_kisyu_zandaka_l(long long genkin,int yokin,int loan_s,int loan_l,long long shihon,int mibarai,int seihin,int genryouhi,int setubi);
	void Set_km_code(int i,int code){mem_km[i]->code=code;};
	void Set_kmr_code(int i,int code){mem_kmr[i]->code=code;};
	int Get_km_code(int i){return mem_km[i]->code;};
	int Get_kmr_code(int i){return mem_kmr[i]->code;};
	void Set_km_zandaka(int i,int zandaka){mem_km[i]->zandaka=zandaka;};
	void Set_km_kisyu_zandaka(int i,int zandaka){mem_km[i]->kisyu_zandaka=zandaka;};
	int Get_km_zandaka(int i){return int(mem_km[i]->zandaka);};
	struct shiwake* Get_sh(int i){return mem_sh[i];};
	void Set_km(struct kanjyo_kamoku *km1){km=km1;};
	void Set_km_kamoku(int i,char *kamoku){strcpy_s(mem_km[i]->kamoku,_countof(mem_km[i]->kamoku),kamoku);};
	void Set_kmr_kamoku(int i,char *kamoku){strcpy_s(mem_kmr[i]->kamoku,_countof(mem_kmr[i]->kamoku),kamoku);};
	void Set_shisan_kamoku(int i,char *kamoku){	strcpy_s(mem_shisan_km[i]->kamoku,_countof(mem_shisan_km[i]->kamoku),kamoku);};
	struct kanjyo_kamoku* Get_km(int i){return mem_km[i];};
	struct kanjyo_kamoku* Get_kmr(int i){return mem_kmr[i];};
	struct shisan_kamoku* Get_shisan_km(int i){return mem_shisan_km[i];};
	struct keihi_kamoku* Get_keihi_km(int i){return mem_keihi_km[i];};
	struct uriage_kamoku* Get_uriage_km(int i){return mem_uriage_km[i];};
	struct husai_kamoku* Get_husai_km(int i){return mem_husai_km[i];};
	void Shisan_table(struct shiwake *sh,struct kanjyo_kamoku *km,FILE *out);
	
	

	
	int strcmp(char *s1,char *s2);
	void Set_shiwake(int i_period,int kari,char *karikata,char *tekiyo,char *kashikata,int kashi,int kari_code,int kashi_code);
	template<class T,class U> void Set_shiwake_T(const T&i_period,const U&kari,char *karikata,char *tekiyo,char *kashikata,const U&kashi,const T&kari_code,const T&kashi_code);
	void Check_km(char *kamoku,int code);
	
	int Get_nkamoku(){nkamoku=mem_km.size();return nkamoku;};
	void Print_kamoku();
	void Set_ndata(int ndata1);
	
	
	
	void Show_kisyu_zandaka(int x,FILE *out3);
	int Get_uriage_total();
	int Get_zaiko();
	int Get_genka();
	int Get_bonus();
	int Get_uriagegenka();
	int Get_syoukyaku();
	int Get_ippankanri();
	int Get_toukirieki();
	int Get_genryou_out(){return int(genryou_out);};
	int Get_setubi_out(){return int(setubi_out);};
	int Get_ukerisi_out(){return int(ukerisi_out);};
	int Get_siharisi_out(){return int(siharisi_out);};
	int Get_kyuyo_out(){return int(kyuyo_out);};
	int Get_bonus_out(){return int(bonus_out);};
	int Get_uriage_out(){return int(uriage_out);};
	int Get_rieki_out(){return int(rieki_out);};
	int Get_genkasyoukyaku_out(){return int(genkasyoukyaku_out);};
	int Get_zaiko_out(){return int(zaiko_out);};
	int Get_kyuyo_c_out(){return int(kyuyo_c_out);};
	int Get_genkin_zandaka(){return int(genkin_kimatu_zandaka);};
	int Get_yokin_zandaka(){return int(yokin_kimatu_zandaka);};
	int Get_loan_l_kimatu_zandaka(){return int(loan_l_kimatu_zandaka);};
	int Get_loan_s_kimatu_zandaka(){return int(loan_s_kimatu_zandaka);};
	int Get_syoumouhin_out(){return int(syoumouhin_out);};
	int Get_houzinzei_out(){return int(houzin_zei_out);};
	int Get_yakuin_housyu_out(){return int(yakuin_housyu_out);};
	int Get_loan_point(){return loan_point;};
	int Get_kimatu_riekizyouyo(){return int(at_km->kimatu_rieki_zyouyo);};
	int Get_kisyu_riekizyouyo(){return int(at_km->kisyu_rieki_zyouyo);};
	int Get_touki_riekizyouyo(){return int(out_touki_zyouyo);};
	int Get_kigyou_hozyokin_out(){return int(kigyou_hozyokin_out);};			//���{���̊�ƕ⏕���o��
	int Get_hozyokin_out(){return int(hozyokin_out);};						//�󂯎�葤�̕⏕���o��
	int Get_kouhukin_out(){return int(kouhukin_out);};

	int Get_hozyokin_out_g();
	int Get_shihon_out();
	void Shisan_tableW(int i_period,int ncase,FILE *out3,FILE *out3_csv);
	void Show_genyokin_suitou(FILE *suitoutyou,FILE *yokin);
	int Get_touki_zeimae_rieki(){return int(at_km->zeimae_soneki);};
	int Get_buy_retailer_out(){return int(buy_retailer_product_out);};
	int Get_karikashi_ac(int index,char *kamoku);
	int Get_kisyu_ac(int index,char *kamoku);
	int Get_kimatu_mibarai_bonus(){return int(at_km->kimatu_mibarai_bonus);};
	int Get_touki_mibarai_bonus(){return int(at_km->touki_mibarai_bonus);};
	int Get_mibarai_bouns(){return int(at_km->mibarai_bonus);};
	void Kessan2(int i_period,int ncase,FILE *out3,FILE *out3_csv);
	__int64 Get_kisyu_shihon_zandaka(){return shihon_kisyu_zandaka;};
	int Get_touki_zyunsoneki(){return at_km->touki_zyun_soneki;}
	int Get_touki_keihi_soukei(){return touki_keihi_soukei;};

	void print_test(){
		for(int i=0;i<int(mem_km.size());i++)
		{
			
		}
	}
	

};
//CAccount.cpp
CAccount::CAccount()
{
	ndata=0;
	genryou_out=0;
	setubi_out=0;
	ukerisi_out=0;
	siharisi_out=0;
	kyuyo_out=0;
	bonus_out=0;
	uriage_out=0;
	zeimae_rieki=0;
	touki_soneki=0;
	rieki_out=0;
	genkasyoukyaku_out=0;
	zaiko_out=0;
	kyuyo_c_out=0;
	zaiko_zandaka_t_1=0;
	houzin_zei_out=0;
	yakuin_housyu_out=0;
	syoumouhin_out=0;
	kigyou_hozyokin_out=0;
	hozyokin_out=0;
	kouhukin_out=0;
	buy_retailer_product_out=0;
	out_touki_zyouyo=0;
	touki_keihi_soukei=0;
	
	//�o�[���n�����ݒ�
	genkin_suitou=new struct suitoutyou;
	genkin_suitou->zandaka=0;	
	mem_genkin_suitou.push_back(genkin_suitou);

	yokin_suitou=new struct suitoutyou;
	yokin_suitou->zandaka=0;
	mem_yokin_suitou.push_back(yokin_suitou);

	//�o�[���n�����ݒ�I��


	//���̑��Ȗځi���Z���g�p�j�����ݒ�
	at_km=new struct ather_kamoku;
	at_km->kimatu_mibarai_zei=0;
	at_km->kiamtu_mibarai_housyu=0;
	at_km->kimatu_rieki_zyouyo=0;
	at_km->kisyu_mibarai_zei=0;
	at_km->kisyu_mibarai_housyu=0;
	at_km->kisyu_rieki_zyouyo=0;
	at_km->mibarai_zei=0;
	at_km->mibarai_housyu=0;
	at_km->rieki_zyouyo=0;
	at_km->touki_zyun_soneki=0;
	at_km->zeimae_soneki=0;
	at_km->touki_mibarai_zei=0;
	at_km->touki_miabrai_housyu=0;
	at_km->kisyu_mibarai_bonus=0;
	at_km->touki_mibarai_bonus=0;
	at_km->mibarai_bonus=0;
	at_km->kimatu_mibarai_bonus=0;
	at_km->minus_soneki=0;
	at_km->mibarai_shouhi_zei=0;
	at_km->touki_mibarai_shouhi_zei=0;
	at_km->kimatu_mibarai_shouhi_zei=0;
	at_km->kisyu_mibarai_shouhi_zei=0;

	for(int i=0;i<7;i++)	mem_riekizyouyo.push_back(0);

	//���̑��Ȗڏ����ݒ�I��

	//�o�͗p�f�[�^�����ݒ�
	out_data=new struct out_kessan_data;
	out_data->bonus_out=0;
	out_data->genkasyoukyaku_out=0;
	out_data->genryou_out=0;
	out_data->houzin_zei=0;
	out_data->yakuin_housyu=0;
	out_data->kigyou_hozyokin=0;
	out_data->kigyou_hozyokin_g=0;
	out_data->kyuyo=0;
	out_data->kyuyo_c=0;
	out_data->kyuyo_out=0;
	out_data->rieki_out=0;
	out_data->setubi_out=0;
	out_data->siharisi_out=0;
	out_data->syotoku_zei=0;
	out_data->syouhisya_kouhukin=0;
	out_data->syouhisya_kouhukin_g=0;
	out_data->syoumouhin=0;
	out_data->ukerisi_out=0;
	out_data->uriage_out=0;
	out_data->zaiko_out=0;
	out_data->zaiko_zandaka_t_1=0;
	out_data->touki_zeigo_rieki=0;
	out_data->touki_zyunsoneki=0;
	//�o�͗p�f�[�^�����ݒ� �I��


}
void CAccount::Kessan(int i_period,int ncase,FILE *out3,FILE *out3_csv)
{	

	if(agent_type==10)								//����҃G�[�W�F���g
	{
		Define_km();								//�ȖڃR�[�h
		if(nkessan==0) Print_kamoku();
		Re_define_km();	//
		Shisan_table(i_period,ncase,out3,out3_csv);	//�d���������ׂĉȖڂɐU�蕪������Ɓityukan_switch=0�j�ŐőO���v���m��
		PLsheet_table(out3,out3_csv);				//PL�V�[�g�ɕK�v�Ȑ��l���v�Z
		Balance_table(out3,out3_csv);				//�o�����X�e�[�u���ɕK�v�Ȑ��l���v�Z
		Calculation_tax();
		Calculation_touki_soneki();					//���v�v�Z�A�ň����㗘�v�m��
		
		Print_pLsheet_table(out3,out3_csv);
		Print_balance_table(out3,out3_csv);

		Show_kimatu_zandaka(ncase,out3);			//
		Convert_kimatu_kisyu();						//�������l�����񐔒l�Ɉڂ��ւ��i�����̍ŏI�����j
		Erase_mem_sh();	
	}
	else if(agent_type==99999)						//�s���G�[�W�F���g
	{
		Define_km();								//�ȖڃR�[�h
		if(nkessan==0) Print_kamoku();
		Re_define_km();	//
		Shisan_table(i_period,ncase,out3,out3_csv);	//�d���������ׂĉȖڂɐU�蕪������Ɓityukan_switch=0�j�ŐőO���v���m��
		PLsheet_table(out3,out3_csv);				//PL�V�[�g�ɕK�v�Ȑ��l���v�Z
		Balance_table(out3,out3_csv);				//�o�����X�e�[�u���ɕK�v�Ȑ��l���v�Z
		Print_pLsheet_table(out3,out3_csv);
		Print_balance_table(out3,out3_csv);

		Show_kimatu_zandaka(ncase,out3);			//
		Convert_kimatu_kisyu();						//�������l�����񐔒l�Ɉڂ��ւ��i�����̍ŏI�����j
		Erase_mem_sh();	
	}
	else											//��ƃG�[�W�F���g�n
	{	
		Define_km();								//�ȖڃR�[�h

		if(nkessan==0) Print_kamoku();
		Re_define_km();	//
		Shisan_table(i_period,ncase,out3,out3_csv);	//�d���������ׂĉȖڂɐU�蕪������Ɓityukan_switch=0�j�ŐőO���v���m��
		PLsheet_table(out3,out3_csv);				//PL�V�[�g�ɕK�v�Ȑ��l���v�Z
		Balance_table(out3,out3_csv);				//�o�����X�e�[�u���ɕK�v�Ȑ��l���v�Z
		if(agent_type==20)Calc_shouhi_tax();		//����ł̌v�Z
		Calc_bonus();								//�{�[�i�X�v�Z
		Calculation_tax();							//�őO���v����Ŋz���v�Z���Čo��
		calc_housyu();
		Calculation_touki_soneki();					//���v�v�Z�A�ň����㗘�v�m��

		
		Print_pLsheet_table(out3,out3_csv);
		Print_balance_table(out3,out3_csv);	
		Loan_s_check();								//�Z���ؓ����O���������Ă��邩�`�F�b�N
		Show_kimatu_zandaka(ncase,out3);			//
		Convert_kimatu_kisyu();						//�������l�����񐔒l�Ɉڂ��ւ��i�����̍ŏI�����j
		Erase_mem_sh();	
		

	}
}
void CAccount::calc_housyu()
{
	long long zeibikigo_rieki=at_km->zeimae_soneki-at_km->minus_soneki-at_km->kimatu_mibarai_zei;	//�v�Z�p�őO���v�ϐ��@zeimae_rieki��PLsheet_table�Ōv�Z�ς�
	long long kurikoshi_soneki=0;		//�֐����A�ȑO�܂ł̑��v�̎g�p�ϐ�
	long long housyu_temp=0;	//�֐����A�x�����`�������闘�v�z�p�ϐ�
	long long calctax	=0;			//�v�Z�����ŋ��p�ϐ�
	int i;

	//�`�`�`�`�`�`�����ŋ��v�Z����
//		printf("agentno=%d , zeimaesoneki=%d , ",Agent_no,ca_rieki);
	if(zeibikigo_rieki>0)		//�őO���v�����݂���ꍇ
	{
		housyu_temp=int(double(zeibikigo_rieki)*double(cpara->Get_PARA_housyu_rate()));
	}
		
	at_km->touki_miabrai_housyu=housyu_temp;
	at_km->kiamtu_mibarai_housyu=at_km->kisyu_mibarai_housyu+at_km->mibarai_housyu+at_km->touki_miabrai_housyu;

}


void CAccount::Loan_s_check()
{//���ݖ��g�p
	fprintf(cpara->FI_Get_se_con(),"agent %d , size=%d\n",Agent_no,mem_km.size());
	for(int i=0;i<int(mem_km.size());i++)
	{
		if(strcmp(mem_km[i]->kamoku,"�Z���ؓ���")==0)
		{
			fprintf(cpara->FI_Get_se_con(),"agent no %d , kisyu %d , kimatu %d\n",Agent_no,mem_km[i]->kisyu_zandaka,mem_km[i]->kimatu_zandaka);
			if(mem_km[i]->kisyu_zandaka<mem_km[i]->kimatu_zandaka)
			{
				loan_point=1;
			}
			else
			{
				loan_point=-1;
			}
		}
	}
}
void CAccount::Calc_shouhi_tax()
{
	int i;
	long long uriage=0;
	long long tax=0;

	for(i=0;i<int(mem_km.size());i++)
	{
		if(strcmp(mem_km[i]->kamoku,"����z")==0)	uriage=mem_km[i]->zandaka;//karikata_total-mem_km[i]->kashikata_total;
	}

	tax=cta->Calc_shouhi_tax(uriage);
	
	at_km->touki_mibarai_shouhi_zei=tax;
	at_km->kimatu_mibarai_shouhi_zei=at_km->kisyu_mibarai_shouhi_zei+at_km->mibarai_shouhi_zei+at_km->touki_mibarai_shouhi_zei;

	
	//	printf("touki_mibarai %d\n",at_km->kimatu_mibarai_bonus);
	//���v�̍ďC��
	at_km->zeimae_soneki=at_km->zeimae_soneki-at_km->touki_mibarai_shouhi_zei;



}
void CAccount::Calc_bonus()
{
	long long calc_bonus;
	long long ca_rieki=at_km->zeimae_soneki;
	long long loan=0;
	long long kisyu_riekizyouyo=0;
	long long minus_soneki=0;
	at_km->minus_soneki=0;

	kisyu_riekizyouyo=at_km->kisyu_rieki_zyouyo;

	if(at_km->zeimae_soneki>0)
	{
		
		if(kisyu_riekizyouyo<0)
		{
			if(-kisyu_riekizyouyo<at_km->zeimae_soneki)
			{
				at_km->minus_soneki=-kisyu_riekizyouyo;
				calc_bonus=long long((at_km->zeimae_soneki-at_km->minus_soneki)*cr->sdrand(cpara->GET_PARA_bonus_rate_min(),cpara->GET_PARA_bonus_rate_max()));
			}
			else	
			{
				calc_bonus=0;
				at_km->minus_soneki=at_km->zeimae_soneki;
			}
		}
		else	calc_bonus=long long((at_km->zeimae_soneki-at_km->minus_soneki)*cr->sdrand(cpara->GET_PARA_bonus_rate_min(),cpara->GET_PARA_bonus_rate_max()));//calc_bonus=at_km->zeimae_soneki*cpara->GET_PARA_bonus_rate_max();
		
	}
	else 	calc_bonus=0;

	at_km->touki_mibarai_bonus=calc_bonus;
	at_km->kimatu_mibarai_bonus=at_km->kisyu_mibarai_bonus+at_km->mibarai_bonus+at_km->touki_mibarai_bonus;
//		printf("kimatu_mibarai_bonus=%d, kisyu_mibarai_bonus=%d, touki_mibarai=%d, mibarai_bonus=%d\n",at_km->kimatu_mibarai_bonus,at_km->kisyu_mibarai_bonus,at_km->touki_mibarai_bonus,at_km->mibarai_bonus);
	//���v�̍ďC��
	at_km->zeimae_soneki=at_km->zeimae_soneki-at_km->touki_mibarai_bonus;


}
void CAccount::Calculation_touki_soneki()
{
	int checker=0;
	if(agent_type==10)		//����҃G�[�W�F���g�̏ꍇ
	{
		at_km->touki_zyun_soneki=at_km->zeimae_soneki-at_km->kimatu_mibarai_zei;
	}
	else
	{

		if(at_km->touki_mibarai_zei>=0)
		{
			at_km->touki_zyun_soneki=at_km->zeimae_soneki-at_km->touki_mibarai_zei-at_km->touki_miabrai_housyu;
		}
		else
		{
			at_km->touki_zyun_soneki=at_km->zeimae_soneki;
		}		
	}

	at_km->rieki_zyouyo=at_km->touki_zyun_soneki;
	out_touki_zyouyo=at_km->rieki_zyouyo;
	at_km->kimatu_rieki_zyouyo=at_km->kisyu_rieki_zyouyo+at_km->rieki_zyouyo;
	
	out_data->touki_zyunsoneki=at_km->rieki_zyouyo;

	
}
void CAccount::kessan_housyu()
{
	at_km->kiamtu_mibarai_housyu=at_km->kisyu_mibarai_housyu+at_km->mibarai_housyu+at_km->touki_miabrai_housyu;
}
void CAccount::Calculation_tax()		//�ŋ��v�Z
{
	long long ca_rieki=at_km->zeimae_soneki-at_km->minus_soneki;	//�v�Z�p�őO���v�ϐ��@zeimae_rieki��PLsheet_table�Ōv�Z�ς�
	long long kurikoshi_soneki=0;		//�֐����A�ȑO�܂ł̑��v�̎g�p�ϐ�
	long long zeimubun_rieki=0;	//�֐����A�x�����`�������闘�v�z�p�ϐ�
	long long calctax	=0;			//�v�Z�����ŋ��p�ϐ�
	int i;


	if(agent_type==10)		//����҃G�[�W�F���g�̏ꍇ
	{
		for(i=0;i<int(mem_km.size());i++)	if(strcmp(mem_km[i]->kamoku,"���^")==0)	zeimubun_rieki=mem_km[i]->zandaka;
		calctax+=cta->Calc_syotoku_tax(zeimubun_rieki);
//		at_km->touki_mibarai_zei=calctax;
		at_km->mibarai_zei+=calctax;		//ather_kamoku�̖����łɒl������
		at_km->kimatu_mibarai_zei=at_km->kisyu_mibarai_zei+at_km->mibarai_zei;	//�����̖����Ł����񖢕��Ł{����������
	}
	else		//��ƌn�G�[�W�F���g�̏ꍇ
	{
		//�`�`�`�`�`�`�����ŋ��v�Z����
//		printf("agentno=%d , zeimaesoneki=%d , ",Agent_no,ca_rieki);
		if(ca_rieki>0)		//�őO���v�����݂���ꍇ
		{
			zeimubun_rieki=ca_rieki;

		}
		else		//�őO���v���Ȃ��ꍇ
		{
			zeimubun_rieki=0;
		}
		calctax+=cta->Calc_houzin_tax(zeimubun_rieki);
//		printf("calctax=%d\n",calctax);
		
		at_km->touki_mibarai_zei=calctax;
		at_km->kimatu_mibarai_zei=at_km->kisyu_mibarai_zei+at_km->mibarai_zei+at_km->touki_mibarai_zei;	//�����̖����Ł����񖢕��Ł{����������

		out_data->touki_zeigo_rieki=at_km->zeimae_soneki-at_km->touki_mibarai_zei;
		//�`�`�`�`�`�`�����ŋ��v�Z�����I��

	}




}


void CAccount::Set_yokin_suitoutyou(int i_period,char *tekiyou,char *tekiyou_aite,char *kamoku,long long amount,int code)
{
	//code=1:�a������
	//code=2:�a������
	int ent;
//	genyo_suitou=new struct genyokin_suitou;
	yokin_suitou=new struct suitoutyou;

	yokin_suitou->i_period=i_period;
	strcpy_s(yokin_suitou->tekiyou,_countof(yokin_suitou->tekiyou),tekiyou);
	strcpy_s(yokin_suitou->tekiyou_aite,_countof(yokin_suitou->tekiyou_aite),tekiyou_aite);
	strcpy_s(yokin_suitou->kamoku,_countof(yokin_suitou->kamoku),kamoku);
	yokin_suitou->code=code;

	
	switch(code)
	{
	case 1:
		yokin_suitou->kari=amount;
		yokin_suitou->zandaka=mem_yokin_suitou[mem_yokin_suitou.size()-1]->zandaka+amount;
		break;

	case 2:
		yokin_suitou->kashi=amount;
		yokin_suitou->zandaka=mem_yokin_suitou[mem_yokin_suitou.size()-1]->zandaka-amount;
		break;

		default:
		printf("error CAccount::Set_genkin_suitoutyou\n please key");
		scanf_s("%d",&ent);
	}

	mem_yokin_suitou.push_back(yokin_suitou);


}
void CAccount::Set_genkin_suitoutyou(int i_period,char *tekiyou,char *tekiyou_aite,char *kamoku,long long amount,int code)
{
	//code=1:��������
	//code=2:��������
	int ent;
	genkin_suitou=new struct suitoutyou;

	genkin_suitou->i_period=i_period;
	strcpy_s(genkin_suitou->tekiyou,_countof(genkin_suitou->tekiyou),tekiyou);
	strcpy_s(genkin_suitou->tekiyou_aite,_countof(genkin_suitou->tekiyou_aite),tekiyou_aite);
	strcpy_s(genkin_suitou->kamoku,_countof(genkin_suitou->kamoku),kamoku);
	genkin_suitou->code=code;
	
	switch(code)
	{
	case 1:
		genkin_suitou->kari=amount;
		genkin_suitou->zandaka=mem_genkin_suitou[mem_genkin_suitou.size()-1]->zandaka+amount;
		break;

	case 2:
		genkin_suitou->kashi=amount;
		genkin_suitou->zandaka=mem_genkin_suitou[mem_genkin_suitou.size()-1]->zandaka-amount;
		break;

	default:
		printf("error CAccount::Set_genkin_suitoutyou\n please key");
		scanf_s("%d",&ent);
	}

	mem_genkin_suitou.push_back(genkin_suitou);


}
void CAccount::Show_genyokin_suitou(FILE *suitoutyou,FILE *yokin)
{
	int i,code;

	for(i=0;i<int(mem_genkin_suitou.size());i++)
	{
		code=mem_genkin_suitou[i]->code;
		switch(code)
		{
		case 0://�J�z
			fprintf(suitoutyou,"%d , %s ,  ,  ,  ,  , %d\n",mem_genkin_suitou[i]->i_period,mem_genkin_suitou[i]->tekiyou,mem_genkin_suitou[i]->zandaka);
			break;
		case 1://��������
			fprintf(suitoutyou,"%d , %s , %s , %s , %d ,  , %d\n",mem_genkin_suitou[i]->i_period,mem_genkin_suitou[i]->tekiyou,mem_genkin_suitou[i]->tekiyou_aite,mem_genkin_suitou[i]->kamoku,mem_genkin_suitou[i]->kari,mem_genkin_suitou[i]->zandaka);
			break;
	
		case 2://�����x�o
			fprintf(suitoutyou,"%d , %s , %s , %s ,  , %d , %d\n",mem_genkin_suitou[i]->i_period,mem_genkin_suitou[i]->tekiyou,mem_genkin_suitou[i]->tekiyou_aite,mem_genkin_suitou[i]->kamoku,mem_genkin_suitou[i]->kashi,mem_genkin_suitou[i]->zandaka);
		break;
		}
	}
	for(i=0;i<int(mem_yokin_suitou.size());i++)
	{
		code=mem_yokin_suitou[i]->code;
		switch(code)
		{
		case 0://�J�z
			fprintf(yokin,"%d , %s ,  ,  ,  ,  , %d \n",mem_yokin_suitou[i]->i_period,mem_yokin_suitou[i]->tekiyou,mem_yokin_suitou[i]->zandaka);
			break;
		case 1://��������
			fprintf(yokin,"%d , %s , %s , %s , %d ,  , %d\n",mem_yokin_suitou[i]->i_period,mem_yokin_suitou[i]->tekiyou,mem_yokin_suitou[i]->tekiyou_aite,mem_yokin_suitou[i]->kamoku,mem_yokin_suitou[i]->kari,mem_yokin_suitou[i]->zandaka);
			break;
	
		case 2://�����x�o
			fprintf(yokin,"%d , %s , %s , %s ,  , %d , %d\n",mem_yokin_suitou[i]->i_period,mem_yokin_suitou[i]->tekiyou,mem_yokin_suitou[i]->tekiyou_aite,mem_yokin_suitou[i]->kamoku,mem_yokin_suitou[i]->kashi,mem_yokin_suitou[i]->zandaka);
		break;
		}
	}

//	printf("%d\n",mem_suitou.size());


}

void CAccount::Reset_genyokin_suitoutyou()
{
	int i;
	int next_period;
	long long zandaka;
	//�����o�[���J�z
	zandaka=mem_genkin_suitou[mem_genkin_suitou.size()-1]->zandaka;
	next_period=mem_genkin_suitou[mem_genkin_suitou.size()-1]->i_period+1;
//	printf("zandaka=%d\n",zandaka);

	i=mem_genkin_suitou.size()-1;
	while(mem_genkin_suitou.size()>0)
	{
//		printf("test , %d , %d\n",i,mem_genkin_suitou.size());
		genkin_suitou=mem_genkin_suitou[i];		//printf("utusikae size=%d\n",mem_genkin_suitou.size());
		mem_genkin_suitou.pop_back();			//printf("pop_back size=%d\n",mem_genkin_suitou.size());
		delete genkin_suitou;					//printf("delete size=%d\n",mem_genkin_suitou.size());
		i=i-1;
//		printf("test\n");		
	}

	genkin_suitou=new struct suitoutyou;
	genkin_suitou->i_period=next_period;
	strcpy_s(genkin_suitou->tekiyou,_countof(genkin_suitou->tekiyou),"�J�z");
	strcpy_s(genkin_suitou->tekiyou_aite,_countof(genkin_suitou->tekiyou_aite)," ");
	strcpy_s(genkin_suitou->kamoku,_countof(genkin_suitou->kamoku)," ");
	genkin_suitou->code=0;
	genkin_suitou->zandaka=zandaka;

	mem_genkin_suitou.push_back(genkin_suitou);



	//�a���o�[���J�z
	zandaka=0;
	zandaka=mem_yokin_suitou[mem_yokin_suitou.size()-1]->zandaka;
	next_period=mem_yokin_suitou[mem_yokin_suitou.size()-1]->i_period+1;

	i=mem_yokin_suitou.size()-1;
	while(mem_yokin_suitou.size()>0)
	{
//		printf("test , %d , %d\n",i,mem_genkin_suitou.size());
		yokin_suitou=mem_yokin_suitou[i];		//printf("utusikae size=%d\n",mem_genkin_suitou.size());
		mem_yokin_suitou.pop_back();			//printf("pop_back size=%d\n",mem_genkin_suitou.size());
		delete yokin_suitou;					//printf("delete size=%d\n",mem_genkin_suitou.size());
		i=i-1;
//		printf("test\n");		
	}

	yokin_suitou=new struct suitoutyou;
	yokin_suitou->i_period=next_period;
	strcpy_s(yokin_suitou->tekiyou,_countof(yokin_suitou->tekiyou),"�J�z");
	strcpy_s(yokin_suitou->tekiyou_aite,_countof(yokin_suitou->tekiyou_aite)," ");
	strcpy_s(yokin_suitou->kamoku,_countof(yokin_suitou->kamoku)," ");
	yokin_suitou->code=0;
	yokin_suitou->zandaka=zandaka;

	mem_yokin_suitou.push_back(yokin_suitou);



}

int CAccount::Get_genka()
{
	int nkamoku;
	long long zaiko;
	int i;
	nkamoku=mem_km.size();
	zaiko=0;
	for(i=0;i<nkamoku;i++)
	{
		if(strcmp(mem_km[i]->kamoku,"���ޗ���")==0)
		{
			zaiko+=mem_km[i]->zandaka;
		}
	}
	return int(zaiko);
}


int CAccount::Get_zaiko()
{
	int nkamoku;
	long long zaiko;
	int i;
	nkamoku=mem_km.size();
	zaiko=0;
	for(i=0;i<nkamoku;i++)
	{
		if(strcmp(mem_km[i]->kamoku,"���i")==0)
		{
			zaiko=mem_km[i]->zandaka-zaiko_zandaka_t_1;
			zaiko_zandaka_t_1=mem_km[i]->zandaka;
		}
	}
	return int(zaiko);
}


int CAccount::Get_uriage_total()
{
	int nkamoku;
	long long uriage_total;
	int i;
	nkamoku=mem_km.size();
	uriage_total=0;
	for(i=0;i<nkamoku;i++)
	{
		if(mem_km[i]->code==3)
		{
			uriage_total+=mem_km[i]->zandaka;
		}
	}
	return int(uriage_total);
}
void CAccount::Set_kisyu_re()
{	//Create�̂Ƃ��̂ݎg�p�����
	//kisyu_kimatu�ɐ��l�Ȃ��̏ꍇ�̖Œ��ꒃ�Ȑ��l�̕ԓ��j�~
	genkin_kisyu_zandaka=0;		chingin_kisyu_zandaka=0;		bank_risoku_u_kisyu_zandaka=0;
	yokin_kisyu_zandaka=0;		rounuhi_kisyu_zandaka=0;		genzairyo_kisyu_zandaka=0;
	loan_s_kisyu_zandaka=0;		bonus_kisyu_zandaka=0;			kyuyo_kisyu_zandaka=0;
	loan_l_kisyu_zandaka=0;		kanrihi_kisyu_zandaka=0;		loan_s_b_kisyu_zandaka=0;
	shihon_kisyu_zandaka=0;		uriage_genka_kisyu_zandaka=0;	loan_l_b_kisyu_zandaka=0;
	mibarai_kisyu_zandaka=0;	uriage_kisyu_zandaka=0;
	seihin_kisyu_zandaka=0;		syoukyaku_kisyu_zandaka=0;
	genryouhi_kisyu_zandaka=0;	kari_risoku_s_kisyu_zandaka=0;
	setubi_kisyu_zandaka=0;		kari_risoku_l_kisyu_zandaka=0;
	yokin_b_kisyu_zandaka=0;
	
}
void CAccount::Set_kimatu_re()
{	//Create�̂Ƃ��̂ݎg�p�����
	genkin_kimatu_zandaka=0;	loan_s_b_kimatu_zandaka=0;
	yokin_kimatu_zandaka=0;		loan_l_b_kimatu_zandaka=0;
	loan_s_kimatu_zandaka=0;
	loan_l_kimatu_zandaka=0;
	shihon_kimatu_zandaka=0;
	mibarai_kimatu_zandaka=0;
	seihin_kimatu_zandaka=0;
	genryouhi_kimatu_zandaka=0;
	setubi_kimatu_zandaka=0;
	yokin_b_kisyu_zandaka=0;
}

void CAccount::Convert_kimatu_kisyu()
{
	
	int i;

	genkin_kisyu_zandaka=genkin_kimatu_zandaka;
	yokin_kisyu_zandaka=yokin_kimatu_zandaka;
	loan_s_kisyu_zandaka=loan_s_kimatu_zandaka;
	loan_l_kisyu_zandaka=loan_l_kimatu_zandaka;
	shihon_kisyu_zandaka=shihon_kimatu_zandaka;
	mibarai_kisyu_zandaka=mibarai_kimatu_zandaka;
	seihin_kisyu_zandaka=seihin_kimatu_zandaka;
	genryouhi_kisyu_zandaka=genryouhi_kimatu_zandaka;
	setubi_kisyu_zandaka=setubi_kimatu_zandaka;
	yokin_b_kisyu_zandaka=yokin_b_kimatu_zandaka;
	loan_s_b_kisyu_zandaka=loan_s_b_kimatu_zandaka;
	loan_l_b_kisyu_zandaka=loan_l_b_kimatu_zandaka;

//	printf("\n");
	for(i=0;i<int(mem_km.size());i++)
	{
		if(mem_km[i]->code==0||mem_km[i]->code==2)
		{
//			if(Agent_no==23)		fprintf(cpara->FI_Get_free_text(),"%s�A����:%d�A����:%d�A����:%d�A",mem_km[i]->kamoku,mem_km[i]->kisyu_zandaka,mem_km[i]->zandaka,mem_km[i]->kimatu_zandaka);
//			printf("%s�A����:%d�A����:%d�A����:%d�A",mem_km[i]->kamoku,mem_km[i]->kisyu_zandaka,mem_km[i]->zandaka,mem_km[i]->kimatu_zandaka);
			mem_km[i]->kisyu_zandaka=mem_km[i]->kimatu_zandaka;
//			printf("�V����:%d\n",mem_km[i]->kisyu_zandaka);
//			if(Agent_no==23)		fprintf(cpara->FI_Get_free_text(),"�V����:%d\n",mem_km[i]->kisyu_zandaka);
		}
		else
		{
//			if(Agent_no==23)		fprintf(cpara->FI_Get_free_text(),"%s�A����:%d�A����:%d�A����:%d�A",mem_km[i]->kamoku,mem_km[i]->kisyu_zandaka,mem_km[i]->zandaka,mem_km[i]->kimatu_zandaka);
			mem_km[i]->kisyu_zandaka=0;
//	if(Agent_no==23)		fprintf(cpara->FI_Get_free_text(),"�V����:%d\n",mem_km[i]->kisyu_zandaka);
		}
	}

	at_km->kisyu_mibarai_zei=at_km->kimatu_mibarai_zei;
	at_km->kisyu_mibarai_housyu=at_km->kiamtu_mibarai_housyu;
	at_km->kisyu_mibarai_shouhi_zei=at_km->kimatu_mibarai_shouhi_zei;
	at_km->kisyu_mibarai_bonus=at_km->kimatu_mibarai_bonus;
	at_km->kisyu_rieki_zyouyo=at_km->kimatu_rieki_zyouyo;

	at_km->rieki_zyouyo=0;
	at_km->mibarai_zei=0;
	at_km->mibarai_housyu=0;
	at_km->mibarai_shouhi_zei=0;
	at_km->mibarai_bonus=0;

}
void CAccount::Set_kisyu_zandaka(int genkin,int yokin,int loan_s,int loan_l,int shihon,int mibarai,int seihin,int genryouhi,int setubi)
{	//Create�̂Ƃ��̂ݎg�p�����
	shihon_kisyu_zandaka=shihon;//���{��
}
void CAccount::Set_kisyu_zandaka_l(long long genkin,int yokin,int loan_s,int loan_l,long long shihon,int mibarai,int seihin,int genryouhi,int setubi)
{	//Create�̂Ƃ��̂ݎg�p�����
	shihon_kisyu_zandaka=shihon;//���{��
}
void CAccount::Get_kimatu_zandaka(int *genkin,int *yokin,int *loan_s,int *loan_l,int *shihon,int *mibarai,int *seihin,int *genryouhi,int *setubi)
{
	*genkin=int(genkin_kimatu_zandaka);
	*yokin=int(yokin_kimatu_zandaka);
	*loan_s=int(loan_s_kimatu_zandaka);
	*loan_l=int(loan_l_kimatu_zandaka);
	*shihon=int(shihon_kimatu_zandaka);
	*mibarai=int(mibarai_kimatu_zandaka);
	*seihin=int(seihin_kimatu_zandaka);
	*genryouhi=int(genryouhi_kimatu_zandaka);
	*setubi=int(setubi_kimatu_zandaka);
//	printf("gen=%d yo=%d los=%d lol=%d\n",genkin_kimatu_zandaka,yokin_kimatu_zandaka,loan_s_kisyu_zandaka,loan_l_kisyu_zandaka);
}

void CAccount::Print_kamoku()
{
	int i;
	fprintf(cpara->FI_Get_out3(),"���Y�ȖځF\n");
	for(i=0;i<int(mem_shisan_km.size());i++){
		fprintf(cpara->FI_Get_out3(),"test %s ",Get_shisan_km(i)->kamoku);fprintf(cpara->FI_Get_out3(),"\n"); 
	}
	fprintf(cpara->FI_Get_out3(),"�o��ȖځF\n");
	for(i=0;i<int(mem_keihi_km.size());i++){
		fprintf(cpara->FI_Get_out3()," %s ",Get_keihi_km(i)->kamoku);fprintf(cpara->FI_Get_out3(),"\n"); 
	}
	fprintf(cpara->FI_Get_out3(),"���ȖځF\n");
	for(i=0;i<int(mem_husai_km.size());i++){
		fprintf(cpara->FI_Get_out3()," %s ",Get_husai_km(i)->kamoku);fprintf(cpara->FI_Get_out3(),"\n"); 
	}
	fprintf(cpara->FI_Get_out3(),"����ȖځF\n");
	for(i=0;i<int(mem_uriage_km.size());i++){
		fprintf(cpara->FI_Get_out3()," %s ",Get_uriage_km(i)->kamoku);fprintf(cpara->FI_Get_out3(),"\n"); 
	}
}
void CAccount::Set_shiwake(int i_period,int kari,char *karikata,char *tekiyo,char *kashikata,int kashi,int kari_code,int kashi_code)
{
	int size;
	size=mem_sh.size();
	sh=new struct shiwake;
	mem_sh.push_back(sh);
	strcpy_s(mem_sh[size]->karikata,_countof(mem_sh[size]->karikata),karikata);
	strcpy_s(mem_sh[size]->kashikata,_countof(mem_sh[size]->kashikata),kashikata);
	strcpy_s(mem_sh[size]->tekiyo,_countof(mem_sh[size]->tekiyo),tekiyo);
	mem_sh[size]->kari=long long(kari);
	mem_sh[size]->kashi=long long(kashi);
	mem_sh[size]->kari_code=kari_code;
	mem_sh[size]->kashi_code=kashi_code;
	Check_km(karikata,kari_code);
	Check_km(kashikata,kashi_code);


	//�����a���o�[���Ǘ�

	//�d�����֐����Ŏg�p���邱�Ƃ��������ꂽ���߁A�E�v�̑��肪�L�q�s�\�A
	//�K�v�ɂȂ����ꍇ�ɔ����Ċ֐��A�\���͈̂ێ������ăX�y�[�X����͂��邱�ƂƂ���
	if(strcmp(karikata,"����")==0)	Set_genkin_suitoutyou(i_period,tekiyo," ",karikata,kari,1);
	else if(strcmp(karikata,"�a��")==0)	Set_yokin_suitoutyou(i_period,tekiyo," ",karikata,kari,1);
	if(strcmp(kashikata,"����")==0) Set_genkin_suitoutyou(i_period,tekiyo," ",kashikata,kashi,2);
	else if(strcmp(kashikata,"�a��")==0) Set_yokin_suitoutyou(i_period,tekiyo," ",kashikata,kashi,2);

}
template<class T,class U> void CAccount::Set_shiwake_T(const T&i_period,const U&kari,char *karikata,char *tekiyo,char *kashikata,const U&kashi,const T&kari_code,const T&kashi_code)
{
	int size;
	size=mem_sh.size();
	sh=new struct shiwake;
	mem_sh.push_back(sh);
	strcpy_s(mem_sh[size]->karikata,_countof(mem_sh[size]->karikata),karikata);
	strcpy_s(mem_sh[size]->kashikata,_countof(mem_sh[size]->kashikata),kashikata);
	strcpy_s(mem_sh[size]->tekiyo,_countof(mem_sh[size]->tekiyo),tekiyo);
	mem_sh[size]->kari=kari;
	mem_sh[size]->kashi=kashi;
	mem_sh[size]->kari_code=kari_code;
	mem_sh[size]->kashi_code=kashi_code;
	Check_km(karikata,kari_code);
	Check_km(kashikata,kashi_code);

	//�����a���o�[���Ǘ�
	//�d�����֐����Ŏg�p���邱�Ƃ��������ꂽ���߁A�E�v�̑��肪�L�q�s�\�A
	//�K�v�ɂȂ����ꍇ�ɔ����Ċ֐��A�\���͈̂ێ������ăX�y�[�X����͂��邱�ƂƂ���
	if(strcmp(karikata,"����")==0)	Set_genkin_suitoutyou(i_period,tekiyo," ",karikata,kari,1);
	else if(strcmp(karikata,"�a��")==0)	Set_yokin_suitoutyou(i_period,tekiyo," ",karikata,kari,1);
	if(strcmp(kashikata,"����")==0) Set_genkin_suitoutyou(i_period,tekiyo," ",kashikata,kashi,2);
	else if(strcmp(kashikata,"�a��")==0) Set_yokin_suitoutyou(i_period,tekiyo," ",kashikata,kashi,2);
}
void CAccount::Check_km(char *kamoku,int code)
{
	int size;int i;
	int np;
	if(code==0)//���Y�Ȗ�
	{
		size=mem_shisan_km.size();
		if(size==0){
			shisan_km=new struct shisan_kamoku;
			mem_shisan_km.push_back(shisan_km);
			strcpy_s(mem_shisan_km[size]->kamoku,_countof(mem_shisan_km[size]->kamoku),kamoku);
	//		fprintf(out3,"inside check_km mem_shisan_km[%d]=%s \n",size,mem_shisan_km[size]);
		}
		else{
			np=0;
			for(i=0;i<size;i++){
				if(strcmp(kamoku,Get_shisan_km(i)->kamoku)==0){np=1;break;}
			}
			if(np==0){
				shisan_km=new struct shisan_kamoku;
				mem_shisan_km.push_back(shisan_km);
				strcpy_s(mem_shisan_km[size]->kamoku,_countof(mem_shisan_km[size]->kamoku),kamoku);
	//			fprintf(out3,"inside check_km mem_shisan_km[%d]=%s \n",size,mem_shisan_km[size]);	
			}
		}
	}
	else if(code==1)//�o��Ȗ�
	{
		size=mem_keihi_km.size();
		if(size==0){
			keihi_km=new struct keihi_kamoku;
			mem_keihi_km.push_back(keihi_km);
			strcpy_s(mem_keihi_km[size]->kamoku,_countof(mem_keihi_km[size]->kamoku),kamoku);
	//		printf("inside check_km mem_keihi_km[%d]=%s \n",size,mem_keihi_km[size]);
	//		fprintf(out3,"inside check_km mem_keihi_km[%d]=%s \n",size,mem_keihi_km[size]);
		}
		else{
			np=0;
			for(i=0;i<size;i++){
				if(strcmp(kamoku,Get_keihi_km(i)->kamoku)==0){np=1;break;}
			}
			if(np==0){
				keihi_km=new struct keihi_kamoku;
				mem_keihi_km.push_back(keihi_km);
				strcpy_s(mem_keihi_km[size]->kamoku,_countof(mem_keihi_km[size]->kamoku),kamoku);
	//			fprintf(out3,"inside check_km mem_keihi_km[%d]=%s \n",size,mem_keihi_km[size]);
			}
		}
	}
	else if(code==2)//���Ȗ�
	{
		size=mem_husai_km.size();
		if(size==0){
			husai_km=new struct husai_kamoku;
			mem_husai_km.push_back(husai_km);
			strcpy_s(mem_husai_km[size]->kamoku,_countof(mem_husai_km[size]->kamoku),kamoku);
	//		fprintf(out3,"inside check_km mem_husai_km[%d]=%s \n",size,mem_husai_km[size]);
		}
		else{
			np=0;
			for(i=0;i<size;i++){
				if(strcmp(kamoku,Get_husai_km(i)->kamoku)==0){np=1;break;}
			}
			if(np==0){
				husai_km=new struct husai_kamoku;
				mem_husai_km.push_back(husai_km);
				strcpy_s(mem_husai_km[size]->kamoku,_countof(mem_husai_km[size]->kamoku),kamoku);
	//			fprintf(out3,"inside check_km mem_husai_km[%d]=%s \n",size,mem_husai_km[size]);
			}
		}
	}
	else if(code==3) //����Ȗ�
	{
		size=mem_uriage_km.size();
		if(size==0){
			uriage_km=new struct uriage_kamoku;
			mem_uriage_km.push_back(uriage_km);
			strcpy_s(mem_uriage_km[size]->kamoku,_countof(mem_uriage_km[size]->kamoku),kamoku);
	//		fprintf(out3,"inside check_km mem_uriage_km[%d]=%s \n",size,mem_uriage_km[size]);
		}
		else{
			np=0;
			for(i=0;i<size;i++){
				if(strcmp(kamoku,Get_uriage_km(i)->kamoku)==0){np=1;break;}
			}
			if(np==0){
				uriage_km=new struct uriage_kamoku;
				mem_uriage_km.push_back(uriage_km);
				strcpy_s(mem_uriage_km[size]->kamoku,_countof(mem_uriage_km[size]->kamoku),kamoku);
	//			fprintf(out3,"inside check_km mem_uriage_km[%d]=%s \n",size,mem_uriage_km[size]);
			}
		}
	}
	else printf("code�ُ�ł�\n");
}
void CAccount::Define_km()	//����Ȗ�mem_km�쐬�ꏊ�A�����ȊO�ł�mem_km��push.back�����Ȃ�
{
	int size,size_km;
	size=mem_sh.size();
	int i,j,np;
	//�ؕ�����Ȗڂ�mem_km�ɂ����
	for(i=0;i<size;i++){
		size_km=mem_km.size();
		if(size_km==0){					//�Ȗڂ�����Ȃ��ꍇ�ɍ쐬����
			km=new struct kanjyo_kamoku;
			km->kisyu_zandaka=0;
			km->kimatu_zandaka=0;
			mem_km.push_back(km);
			strcpy_s(mem_km[size_km]->kamoku,_countof(mem_km[size_km]->kamoku),mem_sh[i]->karikata);
			Set_km_code(size_km,mem_sh[i]->kari_code);
//			printf("kamoku=%s karikata=%s c=%d\n",mem_km[size_km]->kamoku,mem_sh[i]->karikata,mem_sh[i]->kari_code);
		}
		else{				//�Ȗڂ��P�ł�����ꍇ�͂���������s
			np=0;
			for(j=0;j<size_km;j++){			//���݂���ȖڂƎd�󒠂��r���A���݂��Ȃ��Ȗڂ�����ꍇ�͐V�K�ɍ쐬
				if(strcmp(mem_sh[i]->karikata,Get_km(j)->kamoku)==0){np=1;break;}
			}
			if(np==0){
				km=new struct kanjyo_kamoku;
				km->kisyu_zandaka=0;
				km->kimatu_zandaka=0;
				mem_km.push_back(km);
				strcpy_s(mem_km[size_km]->kamoku,_countof(mem_km[size_km]->kamoku),mem_sh[i]->karikata);
				Set_km_code(size_km,mem_sh[i]->kari_code);
//				printf("kamoku=%s karikata=%s c=%d\n",mem_km[size_km]->kamoku,mem_sh[i]->karikata,mem_sh[i]->kari_code);
			}
		}//else�̏I���

	}
	//�ݕ�����Ȗڂ�mem_km�ɂ����
	for(i=0;i<size;i++){
		size_km=mem_km.size();
		if(size_km==0){
			km=new struct kanjyo_kamoku;
			km->kisyu_zandaka=0;
			km->kimatu_zandaka=0;
			mem_km.push_back(km);
			strcpy_s(mem_km[size_km]->kamoku,_countof(mem_km[size_km]->kamoku),mem_sh[i]->kashikata);
			Set_km_code(size_km,mem_sh[i]->kashi_code);
//			printf("kamoku=%s kashikata=%s c=%d\n",mem_km[size_km]->kamoku,mem_sh[i]->kashikata,mem_sh[i]->kashi_code);
		}
		else{
			np=0;
			for(j=0;j<size_km;j++){
				if(strcmp(mem_sh[i]->kashikata,Get_km(j)->kamoku)==0){np=1;break;}
			}
			if(np==0){
				km=new struct kanjyo_kamoku;
				km->kisyu_zandaka=0;
				km->kimatu_zandaka=0;
				mem_km.push_back(km);
				strcpy_s(mem_km[size_km]->kamoku,_countof(mem_km[size_km]->kamoku),mem_sh[i]->kashikata);
				Set_km_code(size_km,mem_sh[i]->kashi_code);
//				printf("kamoku=%s kashikata=%s c=%d\n",mem_km[size_km]->kamoku,mem_sh[i]->kashikata,mem_sh[i]->kashi_code);
			}
		}//else�̏I���
	}
}

void CAccount::Set_ndata(int ndata1)
{
	ndata=ndata1;
}
void CAccount::Re_define_km()
{

	int i,j;
	int p=0,p0=0;//int np;
	int nshisan,nhusai,nuriage,nkeihi;
	nshisan=0;nhusai=0;nuriage=0;nkeihi=0;
	p=0;p0=0;
	
	nkamoku=mem_km.size();
	//���Y�Ȗڂ̒�`--------------------  
	for(i=0;i<nkamoku;i++){
		if(Get_km(i)->code==0) nshisan++;
	}
	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"nshisan_kamoku=%d ",nshisan);
	for(j=0;j<nshisan;j++){
		for(i=0;i<nkamoku;i++){
			if(strcmp(Get_km(i)->kamoku,Get_shisan_km(j)->kamoku)==0)
			{
				kmr=new struct kanjyo_kamoku;
				mem_kmr.push_back(kmr);
				Set_kmr_kamoku(p,Get_km(i)->kamoku);
				Set_kmr_code(p,Get_km_code(i));
				p++;
			}
		}
	}
	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"���Y�Ȗڐ�=%d p=%d ",nshisan,p-p0);
	for(i=0;i<p-p0;i++) if(nkessan==0) fprintf(cpara->FI_Get_out3()," %s ",Get_kmr(i)->kamoku);
	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"\n"); 
	p0=p;

	//���Ȗڂ̒�`-----------------
	for(i=0;i<nkamoku;i++){
//		printf("%s\n",mem_km[i]->kamoku);
		if(Get_km(i)->code==2) nhusai++;
	}
	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"nhusai_kamoku=%d ",nhusai);
	for(j=0;j<nhusai;j++){
		for(i=0;i<nkamoku;i++){//printf("ac %d %s,%d\n",i,Get_km(i),j);
			if(strcmp(Get_km(i)->kamoku,Get_husai_km(j)->kamoku)==0)
			{//printf("aac %d,%d\n",i,j);
				kmr=new struct kanjyo_kamoku;
				mem_kmr.push_back(kmr);
				Set_kmr_kamoku(p,Get_km(i)->kamoku);
				Set_kmr_code(p,Get_km_code(i));
				p++;
			}
		}
	}

	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"���Ȗڐ�=%d p=%d ",nhusai,p-p0);
	for(i=p0;i<p;i++) if(nkessan==0) fprintf(cpara->FI_Get_out3()," %s ",Get_kmr(i)->kamoku);
	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"\n"); 
	p0=p;
	//����Ȗڂ̒�`--------------------
	for(i=0;i<nkamoku;i++){
		if(Get_km(i)->code==3) nuriage++;
	}
//	printf("nuriage_kamoku=%d ",nuriage);
	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"nuriage_kamoku=%d ",nuriage);
	for(j=0;j<nuriage;j++){
		for(i=0;i<nkamoku;i++){
			if(strcmp(Get_km(i)->kamoku,Get_uriage_km(j)->kamoku)==0)
			{
				kmr=new struct kanjyo_kamoku;
				mem_kmr.push_back(kmr);
				Set_kmr_kamoku(p,Get_km(i)->kamoku);
				Set_kmr_code(p,Get_km_code(i));
				p++;
			}
		}
	}

	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"����Ȗڐ�=%d p=%d ",nuriage,p-p0);
//	printf("����Ȗڐ�=%d p=%d \n",nuriage,p-p0);
	for(i=p0;i<p;i++) if(nkessan==0) fprintf(cpara->FI_Get_out3()," %s ",Get_kmr(i)->kamoku);
	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"\n"); 
	p0=p;

	//�o��Ȗڂ̍Ē�`--------------------
	for(i=0;i<nkamoku;i++){
		if(Get_km(i)->code==1) nkeihi++;
	}
	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"nkeihi_kamoku=%d ",nkeihi);
	for(j=0;j<nkeihi;j++){
		for(i=0;i<nkamoku;i++){
			if(strcmp(Get_km(i)->kamoku,Get_keihi_km(j)->kamoku)==0)
			{
				kmr=new struct kanjyo_kamoku;
				mem_kmr.push_back(kmr);
				Set_kmr_kamoku(p,Get_km(i)->kamoku);
				Set_kmr_code(p,Get_km_code(i));
				p++;
			}
		}
	}
	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"�o��Ȗڐ�=%d p=%d \n",nkeihi,p-p0);
	for(i=p0;i<p;i++) if(nkessan==0) fprintf(cpara->FI_Get_out3()," %s ",Get_kmr(i)->kamoku);
	if(nkessan==0) fprintf(cpara->FI_Get_out3(),"\n"); 
	//kmr�̊m�F
	for(i=0;i<nkamoku;i++){
		if(nkessan==0) fprintf(cpara->FI_Get_out3(),"km[%3d] %20s  code=%3d  kmr[%3d] %20s code=%3d\n",i,Get_km(i)->kamoku,Get_km_code(i),i,Get_kmr(i)->kamoku,Get_kmr_code(i));
	}
	for(i=0;i<nkamoku;i++){//printf("checckeraaaa  %s�A����:%d�A����:%d�A����:%d\n",mem_km[i]->kamoku,mem_km[i]->kisyu_zandaka,mem_km[i]->zandaka,mem_km[i]->kimatu_zandaka);
		Set_km_kamoku(i,Get_kmr(i)->kamoku);
		Set_km_code(i,Get_kmr_code(i));
		//printf("checckeraaaa  %s�A����:%d�A����:%d�A����:%d\n",mem_km[i]->kamoku,mem_km[i]->kisyu_zandaka,mem_km[i]->zandaka,mem_km[i]->kimatu_zandaka);
	}
	for(i=0;i<nkamoku;i++){
//		printf("km[%3d] %20s  code=%3d  kmr[%3d] %20s code=%3d\n",i,Get_km(i)->kamoku,Get_km_code(i),i,Get_kmr(i)->kamoku,Get_kmr_code(i));
	}

}
int CAccount::strcmp(char *s1,char *s2)
{
	int i=0,p=0;
	while(s1[i]){  //s1[i]��NULL�ɂȂ�܂ŌJ��Ԃ�
		if(s1[i]==s2[i]) p++;
		i++;
	}
	if(p==i) return 0;//������s1�ƕ�����s2�������ł����0��Ԃ�
	else return 1;
}

void CAccount::Shisan_table(int i_period,int ncase,FILE *out3,FILE *out3_csv)
{

	//ncase=0;//printed out
	//ncase=1;//total only printed out
	//ncase=2;//not printed out

	int i,j;
	long long kari_total=0,kashi_total=0;
	long long zandaka=0;
	int pp=0;
	ndata=mem_sh.size();
	if(ncase==0) fprintf(out3,"ndata=%d nkamoku=%d \n",ndata,nkamoku);
//	printf("ndata=%d nkamoku=%d \n",ndata,nkamoku);
	for(j=0;j<nkamoku;j++){		
	//---------
			//����c��(�O���J�z���j�̐ݒ�

		if(mem_km[j]->code==0){
			if(strcmp(mem_km[j]->kamoku,"����")==0){ 
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�a��")==0){
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�ݔ�")==0){
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"����")==0){
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"���i")==0){
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"��z�Œ莑�{�`��")==0){
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�Z���ݏo��")==0){
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�����ݏo��")==0){
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
		}
		else if(mem_km[j]->code==2){
			if(strcmp(mem_km[j]->kamoku,"�Z���ؓ���")==0) {
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�����ؓ���")==0){
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�a��_Bank")==0) {
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"���厑�{")==0) {
				if(i_period==0){
					mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
				}
				else{
					mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
				}
			}
			else if(strcmp(mem_km[j]->kamoku,"������p")==0) {
				mem_km[j]->zandaka=mem_km[j]->kisyu_zandaka;
			}
		}
		else{
			mem_km[j]->kisyu_zandaka=0;
			mem_km[j]->zandaka=0;
		}
//-----------------------------------����c��(�O���J�z���j�̐ݒ�I��
	}//for(j=0;...�̏I���

	
	//�����茳���̌v�Z
	for(j=0;j<nkamoku;j++)
	{
		zandaka=Get_km_zandaka(j);
		pp=0;
		mem_km[j]->karikata_total=0;
		mem_km[j]->kashikata_total=0;
		if(ncase==0 ){
			fprintf(out3,"\n");
			fprintf(out3,"          -------------------------------\n");
			fprintf(out3,"                     %s \n",mem_km[j]->kamoku);
			fprintf(out3,"          -------------------------------\n");
			fprintf(out3,"               ����Ȗځ@                              �@�@  �@�ؕ��@�@�@�@�ݕ�        �c��\n");
			fprintf(out3_csv,"\n");
			fprintf(out3_csv,"   ,     ,  -------------------------------,\n");
			fprintf(out3_csv,"   ,     ,               %s          ,\n",mem_km[j]->kamoku);
			fprintf(out3_csv,"    ,    ,  -------------------------------,\n");
			fprintf(out3_csv,"          ,     ����Ȗځ@,                              �@�@  ,�@�ؕ��@,�@�@�@�ݕ�    ,    �c��\n");
		}

		
		for(i=0;i<ndata;i++)
		{

			if(i==0) 
			{
				if(Get_km_code(j)==0)
				{
					if(ncase==0)
					{
						fprintf(out3,"           �@�@�@ �@�@�@�@�@�@�@�@�@�@�O���J�z�@�@�@�@�@�@�@%10lld    �@�@ �@�@�@�@%10lld\n",Get_km_zandaka(j),Get_km_zandaka(j));
						fprintf(out3_csv,"       ,�@�@�@,�@�@g�O���J�z,�@�@%10lld ,  �@,%10lld\n",Get_km_zandaka(j),Get_km_zandaka(j));
					}
				}
				else if( Get_km_code(j)==2)
				{
					if(ncase==0)
					{
						fprintf(out3,"         �@�@�@�@  �@�@�@ �@�@�@�@�@�@�O���J�z �@�@�@ �@�@�@�@�@�@�@�@  %10lld     %10lld\n",Get_km_zandaka(j),Get_km_zandaka(j));
						fprintf(out3_csv,"  �@,�@�@�@,�@g�O���J�z ,  ,%10lld,     %10lld\n",Get_km_zandaka(j),Get_km_zandaka(j));
					}
				}	
			}//if(i==0�̏I���
			if(strcmp(mem_sh[i]->karikata,mem_km[j]->kamoku)==0 && strcmp(mem_km[j]->kamoku,mem_sh[i]->karikata)==0)
			{
				if(mem_km[j]->code==0 || mem_km[j]->code==1) {
					mem_km[j]->zandaka+=mem_sh[i]->kari;
				}
				else {
					mem_km[j]->zandaka-=mem_sh[i]->kari;
				}
				if(ncase==0){
					fprintf(out3,"%12d %12s %30s  %10d           %10d\n",i_period,mem_sh[i]->kashikata,mem_sh[i]->tekiyo,mem_sh[i]->kari,mem_km[j]->zandaka);
					fprintf(out3_csv,"%12d, %12s, %30s,  %10d,           ,%10d\n",i_period,mem_sh[i]->kashikata,mem_sh[i]->tekiyo,mem_sh[i]->kari,mem_km[j]->zandaka);
				}
				mem_km[j]->karikata_total+=mem_sh[i]->kari;
				

			}
			else if(strcmp(mem_sh[i]->kashikata,mem_km[j]->kamoku)==0 && strcmp(mem_km[j]->kamoku,mem_sh[i]->kashikata)==0)
			{
				if(mem_km[j]->code==0 || mem_km[j]->code==1) mem_km[j]->zandaka-=mem_sh[i]->kashi;
				else mem_km[j]->zandaka+=mem_sh[i]->kashi;
				if(ncase==0){
					fprintf(out3,"%12d %12s %30s           %10d  %10d \n",i_period,mem_sh[i]->karikata,mem_sh[i]->tekiyo,mem_sh[i]->kashi,mem_km[j]->zandaka);
					fprintf(out3_csv,"%12d, %12s, %30s,           ,%10d,  %10d\n",i_period,mem_sh[i]->karikata,mem_sh[i]->tekiyo,mem_sh[i]->kashi,mem_km[j]->zandaka);
				}
				mem_km[j]->kashikata_total+=long long(mem_sh[i]->kashi);
				

			}
			

		}//for(i=0;...�̏I���
		if(ncase==0){
			fprintf(out3,"            ----------------------------------------\n");
			fprintf(out3,"                ���v                                        %8d  %8d\n",mem_km[j]->karikata_total,mem_km[j]->kashikata_total);
			fprintf(out3_csv,"            ,----------------------------------------\n");
			fprintf(out3_csv,"            ,    ���v  ,        ,  %8lld , %8lld\n",mem_km[j]->karikata_total,mem_km[j]->kashikata_total);
		}

	
	if(strcmp(mem_km[j]->kamoku,"����")==0) genryou_out=mem_km[j]->karikata_total;	
	if(strcmp(mem_km[j]->kamoku,"�J����")==0) kyuyo_out=mem_km[j]->karikata_total;
	if(strcmp(mem_km[j]->kamoku,"����")==0) kyuyo_out=mem_km[j]->karikata_total;
	if(strcmp(mem_km[j]->kamoku,"�{�[�i�X��")==0) bonus_out=mem_km[j]->karikata_total;
	if(strcmp(mem_km[j]->kamoku,"���^")==0) kyuyo_c_out=mem_km[j]->kashikata_total;	
	if(strcmp(mem_km[j]->kamoku,"�D����t��")==0) kouhukin_out=mem_km[j]->kashikata_total;
	if(strcmp(mem_km[j]->kamoku,"��ƕ⏕��")==0) out_data->kigyou_hozyokin_g=mem_km[j]->kashikata_total;
	if(strcmp(mem_km[j]->kamoku,"���Օi")==0) syoumouhin_out=mem_km[j]->karikata_total;
	if(strcmp(mem_km[j]->kamoku,"���e�C���[���i")==0)buy_retailer_product_out=mem_km[j]->karikata_total;
	}//for(j=0;...�̏I���

	if(ncase==0 || ncase==1){
		fprintf(out3_csv,"agent_type=%d    agent_no=%d\n",agent_type,Agent_no);
		fprintf(out3,"\n");
		fprintf(out3,"           ����Ȗځ@  �R�[�h�@ �@�ؕ��@  �@�ݕ�\n");
		fprintf(out3_csv,"\n");
		fprintf(out3_csv,"    ,      , ����Ȗځ@, �@�ؕ��@,  �@�ݕ�\n");
	}
	for(j=0;j<nkamoku;j++)
	{
		if(ncase==0 || ncase==1){
			fprintf(out3," %20s %4d      %8d  %8d \n",mem_km[j]->kamoku,mem_km[j]->code,mem_km[j]->karikata_total,mem_km[j]->kashikata_total);
			fprintf(out3_csv," ,  ,%20s,  %8lld , %8lld\n",mem_km[j]->kamoku,mem_km[j]->karikata_total,mem_km[j]->kashikata_total);
		}
		kari_total+=mem_km[j]->karikata_total;
		kashi_total+=mem_km[j]->kashikata_total;
	}

		if(ncase==0 || ncase==1){
			fprintf(out3," ������V	         %8lld \n",at_km->mibarai_housyu);
			fprintf(out3_csv," ,  ,������V,   , %8lld\n",at_km->mibarai_housyu);
			fprintf(out3," �����	         %8lld \n",at_km->mibarai_shouhi_zei);
			fprintf(out3_csv," ,  ,�����,   , %8lld\n",at_km->mibarai_shouhi_zei);
			fprintf(out3," �@�l��	         %8lld \n",at_km->mibarai_zei);
			fprintf(out3_csv," ,  ,�@�l��,   , %8lld\n",at_km->mibarai_zei);
			fprintf(out3," �{�[�i�X	         %8d \n",at_km->mibarai_bonus);
			fprintf(out3_csv," ,  ,�{�[�i�X,   , %8lld\n",at_km->mibarai_bonus);
		}
		kashi_total+=at_km->mibarai_zei+at_km->mibarai_shouhi_zei+at_km->mibarai_housyu;
		kashi_total+=at_km->mibarai_bonus;

	if(ncase==0 || ncase==1){
		fprintf(out3,"            ----------------------------------------\n");
		fprintf(out3,"            ���v                %8d  %8d\n",kari_total,kashi_total);
		fprintf(out3_csv,"    ,        ,----------------------------------------\n");
		fprintf(out3_csv,"    ,   ,     ���v      ,   %8lld , %8lld\n",kari_total,kashi_total);
		fprintf(out3,"\n");
		fprintf(out3_csv,"\n");
	}


	for(j=0;j<nkamoku;j++)
	{
		//�����c��(�����J�z���j�̐ݒ�
		if(mem_km[j]->code==0){
			if(strcmp(mem_km[j]->kamoku,"����")==0){ 
				genkin_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�a��")==0){
				yokin_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�ݔ�")==0){
				setubi_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"����")==0){
				genryouhi_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"���i")==0){
				seihin_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�Z���ݏo��")==0){
				loan_s_b_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�����ݏo��")==0){
				loan_l_b_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else
			{
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
		}
		else if(mem_km[j]->code==2){
			if(strcmp(mem_km[j]->kamoku,"�Z���ؓ���")==0) {
				loan_s_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�����ؓ���")==0) {
				loan_l_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"�a��_Bank")==0) {
				yokin_b_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"���厑�{")==0) {
				shihon_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else if(strcmp(mem_km[j]->kamoku,"������p")==0) {
				mibarai_kimatu_zandaka=mem_km[j]->zandaka;
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
			else
			{
				mem_km[j]->kimatu_zandaka=mem_km[j]->zandaka;
			}
		}
	}//for(j=0;...�̏I���
}
void CAccount::Show_kimatu_zandaka(int x,FILE *out3)
{
	//x=0;//not bank
	//x=1;//bank
	shihon_kimatu_zandaka=shihon_kisyu_zandaka+rieki;
	if(shihon_kimatu_zandaka<0) shihon_kimatu_zandaka=0;

	if(nkessan==0 || nkessan==1){
		fprintf(out3,"�����c���@����=%d�@�a��=%d�@�Z���ؓ���=%d�@�����ؓ���=%d�@���厑�{=%d ���i=%d ����=%d �ݔ�=%d ������p=%d\n",genkin_kimatu_zandaka,yokin_kimatu_zandaka,loan_s_kimatu_zandaka,loan_l_kimatu_zandaka,shihon_kimatu_zandaka,seihin_kimatu_zandaka,genryouhi_kimatu_zandaka,setubi_kimatu_zandaka,mibarai_kimatu_zandaka);
		if(x==1)  fprintf(out3,"          �a��_Bank=%d �Z���ؓ���=%d�@�����ؓ���=%d\n",yokin_b_kimatu_zandaka,loan_s_b_kimatu_zandaka,loan_l_b_kimatu_zandaka);
		fprintf(out3,"\n");
	}

}
void CAccount::Show_kisyu_zandaka(int x,FILE *out3)
{
	//x=0;//not bank
	//x=1;//bank
	if(nkessan==0 || nkessan==1){
		fprintf(out3,"����c���@����=%d�@�a��=%d�@�Z���ؓ���=%d�@�����ؓ���=%d�@���厑�{=%d ���i=%d ����=%d �ݔ�=%d ������p=%d\n",genkin_kisyu_zandaka,yokin_kisyu_zandaka,loan_s_kisyu_zandaka,loan_l_kisyu_zandaka,shihon_kisyu_zandaka,seihin_kisyu_zandaka,genryouhi_kisyu_zandaka,setubi_kisyu_zandaka,mibarai_kisyu_zandaka);
		if(x==1) fprintf(out3,"          �a��_Bank=%d �Z���ؓ���=%d�@�����ؓ���=%d\n",yokin_b_kisyu_zandaka,loan_s_b_kisyu_zandaka,loan_l_b_kisyu_zandaka);
		fprintf(out3,"\n");
	}
}

void CAccount::PLsheet_table(FILE *out3,FILE *out3_csv)
{
	int j;
	long long kari_total=0,kashi_total=0;
	int nkamoku=mem_km.size();
	
	//�����Ȗڂ̋L��
	for(j=0;j<nkamoku;j++)
	{
		if(mem_km[j]->code==3)
		{
			kashi_total+=mem_km[j]->kashikata_total-mem_km[j]->karikata_total;
			if(strcmp(mem_km[j]->kamoku,"����z")==0) uriage_out=mem_km[j]->kashikata_total-mem_km[j]->karikata_total;
			if(strcmp(mem_km[j]->kamoku,"��旘��")==0) ukerisi_out=mem_km[j]->kashikata_total-mem_km[j]->karikata_total;
			if(strcmp(mem_km[j]->kamoku,"�⏕��")==0) hozyokin_out=mem_km[j]->kashikata_total-mem_km[j]->karikata_total;
		}
	}
	//�o��Ȗڂ̋L��
	for(j=0;j<nkamoku;j++)
	{
		if(mem_km[j]->code==1)
		{
			kari_total+=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
			if(strcmp(mem_km[j]->kamoku,"�������p��")==0) genkasyoukyaku_out=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
			if(strcmp(mem_km[j]->kamoku,"�x������")==0) siharisi_out=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
			if(strcmp(mem_km[j]->kamoku,"��ƕ⏕��")==0)kigyou_hozyokin_out=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
			if(strcmp(mem_km[j]->kamoku,"�@�l��")==0) houzin_zei_out=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
			if(strcmp(mem_km[j]->kamoku,"������V")==0) yakuin_housyu_out=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
		}
	}
	
	rieki=kashi_total-kari_total;
	pl_rieki=kashi_total-kari_total;
	at_km->zeimae_soneki=kashi_total-kari_total;
	//if(Agent_no==7) 	printf("rieki %d\n",rieki);


}
void CAccount::Balance_table(FILE *out3,FILE *out3_csv)
{
	int j;
	long long kari_total=0,kashi_total=0;
	long long kari_kashi=0,kashi_kari=0;
	int nkamoku=mem_km.size();
	int dumy;	//�G���[�R�[�h����scanf�ҋ@�p�֐�

	for(j=0;j<nkamoku;j++)
	{
		if(mem_km[j]->code==0)
		{
			kari_kashi=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
			kari_total+=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
			if(strcmp(mem_km[j]->kamoku,"���i")==0) zaiko_out=kari_kashi;
			if(strcmp(mem_km[j]->kamoku,"�ݔ�")==0) setubi_out=mem_km[j]->karikata_total;
		}
		if(mem_km[j]->code==2)
		{
			kashi_kari=mem_km[j]->kashikata_total-mem_km[j]->karikata_total;
			kashi_total+=mem_km[j]->kashikata_total-mem_km[j]->karikata_total;
		}

	}


	kashi_total+=at_km->mibarai_zei+at_km->mibarai_shouhi_zei;
	kashi_total+=at_km->mibarai_bonus;
	kashi_total+=at_km->mibarai_housyu;
	rieki=kari_total-kashi_total;
	rieki_out=rieki;
	bl_rieki=kari_total-kashi_total;
	zeimae_rieki=bl_rieki;
	
	if(rieki!=at_km->zeimae_soneki)
	{
		printf("\n\n PL��BL�Ōv�Z���ꂽ�őO���v�̓��e���قȂ�܂��B�K���ȃL�[����͂��Ă�������\n");
		printf("ag_no:%d , BL:%d , PL%d , zei:%d\n",Agent_no,rieki , at_km->zeimae_soneki,at_km->mibarai_zei);
		scanf_s("%d",&dumy);
	}

}
void CAccount::Print_pLsheet_table(FILE *out3,FILE *out3_csv)
{
	int j;
	long long kari_total=0,kashi_total=0;
	int nkamoku=mem_km.size();
	if(nkessan==0||nkessan==1){
		fprintf(out3,"���v�v�Z��\n");
		fprintf(out3,"           ����Ȗځ@  �R�[�h�@ �@�ؕ��@  �@�ݕ�\n");
		fprintf(out3_csv,"���v�v�Z��\n");
		fprintf(out3_csv,"   ,      ,  ����Ȗ�, �@�ؕ��@,  �@�ݕ�\n");
	}
	//�����Ȗڂ̋L��
	for(j=0;j<nkamoku;j++){
			if(mem_km[j]->code==3){
				if(nkessan==0 || nkessan==1){
					fprintf(out3," %20s %4d                 %8d\n",mem_km[j]->kamoku,mem_km[j]->code,mem_km[j]->kashikata_total-mem_km[j]->karikata_total);
		//			printf("j=%d %20s %4d                 %8d\n",j,mem_km[j]->kamoku,mem_km[j]->code,mem_km[j]->kashikata_total-mem_km[j]->karikata_total);
					fprintf(out3_csv,"  ,   ,%20s ,         ,  %8lld\n",mem_km[j]->kamoku,mem_km[j]->kashikata_total-mem_km[j]->karikata_total);
				}
			kashi_total+=mem_km[j]->kashikata_total-mem_km[j]->karikata_total;
			if(strcmp(mem_km[j]->kamoku,"����z")==0) uriage_out=mem_km[j]->kashikata_total-mem_km[j]->karikata_total;
			if(strcmp(mem_km[j]->kamoku,"��旘��")==0) ukerisi_out=mem_km[j]->kashikata_total-mem_km[j]->karikata_total;	
		}
	}
	//�o��Ȗڂ̋L��
	for(j=0;j<nkamoku;j++){
			if(mem_km[j]->code==1)
			{
				if(strcmp(mem_km[j]->kamoku,"�œ������z")!=0)
				{
					if(nkessan==0 || nkessan==1){
						fprintf(out3," %20s %4d     %8d\n",mem_km[j]->kamoku,mem_km[j]->code,mem_km[j]->karikata_total-mem_km[j]->kashikata_total);
//						printf("j=%d %20s %4d     %8d\n",j,mem_km[j]->kamoku,mem_km[j]->code,mem_km[j]->karikata_total-mem_km[j]->kashikata_total);
						fprintf(out3_csv,"  ,  ,%20s,  %8lld\n",mem_km[j]->kamoku,mem_km[j]->karikata_total-mem_km[j]->kashikata_total);
					}
				kari_total+=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
				if(strcmp(mem_km[j]->kamoku,"�������p��")==0) genkasyoukyaku_out=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
				if(strcmp(mem_km[j]->kamoku,"�x������")==0) siharisi_out=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
				if(strcmp(mem_km[j]->kamoku,"�@�l��")==0) houzin_zei_out=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
				if(strcmp(mem_km[j]->kamoku,"������V")==0) yakuin_housyu_out=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
				}
		}
	}


	
	
	
//	rieki=kashi_total-kari_total;
	if(nkessan==0 || nkessan==1){
		fprintf(out3,"            �����{�[�i�X       %8d\n",at_km->touki_mibarai_bonus);
		fprintf(out3,"            �������v           %8d\n",at_km->zeimae_soneki);
		fprintf(out3,"            ----------------------------------------\n");
		fprintf(out3,"            ���v               %8d    %8d\n",kari_total+at_km->zeimae_soneki+at_km->touki_mibarai_bonus,kashi_total);
		fprintf(out3_csv,"     ,     ,  �����{�[�i�X   ,        %8lld\n",at_km->touki_mibarai_bonus);
		fprintf(out3_csv,"     ,     ,  �ň����O���v   ,        %8lld\n",at_km->zeimae_soneki);
		fprintf(out3_csv,"     ,       ,----------------------------------------\n");
		fprintf(out3_csv,"     ,      , ���v ,              %8lld  ,  %8lld\n",kari_total+at_km->zeimae_soneki+at_km->touki_mibarai_bonus,kashi_total);
		fprintf(out3,"\n");
		fprintf(out3_csv,"\n");
	}

	touki_keihi_soukei=kari_total+at_km->touki_mibarai_bonus;

}
void CAccount::Print_balance_table(FILE *out3,FILE *out3_csv)
{
	int j;
	long long kari_total=0,kashi_total=0;
	long long kari_kashi=0,kashi_kari=0;
	long long kimatu_kashi=0,kimatu_kari=0;
	long long yozyou=0;
	int nkamoku=mem_km.size();
	if(nkessan==0 || nkessan==1){
		fprintf(out3_csv,"agent_type=%d    agent_no=%d\n",agent_type,Agent_no);
		fprintf(out3,"�ݎؑΏƕ\\n");
		fprintf(out3,"           ����Ȗځ@  �R�[�h�@ �@�ؕ��@  �@�ݕ�\n");
		fprintf(out3_csv,"�ݎؑΏƕ\\n");
		fprintf(out3_csv,"  ,  ,����Ȗ� ,�ؕ�����c��,�ݕ�����c��, �ؕ� , �ݕ� , �ؕ������c�� ,�ݕ������c��\n");
	}
	//���{�Ȗڂ̋L�q
	for(j=0;j<nkamoku;j++)
	{
		if(mem_km[j]->code==0)
		{
			kari_kashi=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
			if(nkessan==0 || nkessan==1){
				fprintf(out3," %20s %4d     %8d\n",mem_km[j]->kamoku,mem_km[j]->code,kari_kashi);
				fprintf(out3_csv," , ,%20s, %8lld,  , %8lld ,  ,  %8lld\n",mem_km[j]->kamoku,mem_km[j]->kisyu_zandaka,kari_kashi,mem_km[j]->kisyu_zandaka+kari_kashi);
			}
			kari_total+=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
			kimatu_kari+=mem_km[j]->kisyu_zandaka+mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
			if(strcmp(mem_km[j]->kamoku,"���i")==0) zaiko_out=kari_kashi;
			if(strcmp(mem_km[j]->kamoku,"�ݔ�")==0) setubi_out=mem_km[j]->karikata_total;
		}
	}


	//���Ȗڂ̋L�q
	for(j=0;j<nkamoku;j++)
	{
		if(mem_km[j]->code==2)
		{
			kashi_kari=mem_km[j]->kashikata_total-mem_km[j]->karikata_total;
			if(nkessan==0 || nkessan==1){
				fprintf(out3," %20s %4d                 %8d\n",mem_km[j]->kamoku,mem_km[j]->code,kashi_kari);
				fprintf(out3_csv," , ,%20s, , %8lld ,  , %8lld ,  ,%8lld\n",mem_km[j]->kamoku,mem_km[j]->kisyu_zandaka,kashi_kari,mem_km[j]->kisyu_zandaka+kashi_kari);
			}
			kashi_total+=mem_km[j]->kashikata_total-mem_km[j]->karikata_total;
			kimatu_kashi+=mem_km[j]->kisyu_zandaka+mem_km[j]->kashikata_total-mem_km[j]->karikata_total;
		}
		
	}

	if(nkessan==0 || nkessan==1){
		fprintf(out3," �����{�[�i�X 0                 %8d\n",at_km->kisyu_mibarai_bonus+at_km->touki_mibarai_bonus);
		fprintf(out3_csv," , ,�����{�[�i�X, , %8lld ,  , %8lld ,  ,%8lld\n",at_km->kisyu_mibarai_bonus,at_km->mibarai_bonus+at_km->touki_mibarai_bonus,at_km->kimatu_mibarai_bonus);
		fprintf(out3," ��������� 0                 %8d\n",at_km->kisyu_mibarai_zei+at_km->touki_mibarai_zei);
		fprintf(out3_csv," , ,���������, , %8lld ,  , %8lld ,  ,%8lld\n",at_km->kisyu_mibarai_shouhi_zei,at_km->mibarai_shouhi_zei+at_km->touki_mibarai_shouhi_zei,at_km->kimatu_mibarai_shouhi_zei);	
		fprintf(out3," ������ 0                 %8d\n",at_km->kisyu_mibarai_zei+at_km->touki_mibarai_zei);
		fprintf(out3_csv," , ,������, , %8lld ,  , %8lld ,  ,%8lld\n",at_km->kisyu_mibarai_zei,at_km->mibarai_zei+at_km->touki_mibarai_zei,at_km->kimatu_mibarai_zei);	
		fprintf(out3," ������V 0                 %8d\n",at_km->kisyu_mibarai_housyu+at_km->touki_miabrai_housyu);
		fprintf(out3_csv," , ,������V, , %8lld ,  , %8lld ,  ,%8lld\n",at_km->kisyu_mibarai_housyu,at_km->mibarai_housyu+at_km->touki_miabrai_housyu,at_km->kiamtu_mibarai_housyu);	
	}
	kashi_total+=at_km->mibarai_zei+at_km->touki_mibarai_zei+at_km->mibarai_housyu+at_km->touki_miabrai_housyu+at_km->mibarai_bonus+at_km->touki_mibarai_bonus;
	kimatu_kashi+=at_km->kimatu_mibarai_zei+at_km->kiamtu_mibarai_housyu+at_km->kimatu_mibarai_bonus;
	
	if(nkessan==0 || nkessan==1){
	fprintf(out3," ���v��] 0                 %8d\n",at_km->rieki_zyouyo);
	fprintf(out3_csv," , ,���v��], , %8lld ,  , %8lld ,  ,%8lld\n",at_km->kisyu_rieki_zyouyo,at_km->rieki_zyouyo,at_km->kimatu_rieki_zyouyo);
	}
	kashi_total+=at_km->rieki_zyouyo;
	kimatu_kashi+=at_km->kimatu_rieki_zyouyo;


	if(nkessan==0 || nkessan==1){

		fprintf(out3,"            ���v               %8d    %8d\n",kari_total,kashi_total+touki_soneki);
		fprintf(out3_csv,"      ,      ,------------------------------------------------------------------\n");
		fprintf(out3_csv,"      ,      ,���v ,  ,  , %8lld , %8lld  ,  %8lld , %8lld\n",kari_total,kashi_total,kimatu_kari,kimatu_kashi);
		fprintf(out3,"\n");
		fprintf(out3_csv,"\n");
	}


}
int CAccount::Get_kamoku(int index,char *kamoku)
{
	//���o���S��
	int j;	long long kimatu=0;
	for(j=0;j<nkamoku;j++)
	{
		if(mem_km[j]->code==index){
			if(strcmp(mem_km[j]->kamoku,kamoku)==0)	kimatu=mem_km[j]->zandaka;
//			printf("xxxx1 j=%d n=%d k1=%d k2=%d  || %d\n",j,nkamoku,kimatu,strcmp(mem_km[j]->kamoku,kamoku));
		}
	}
	return int(kimatu);
}
long long CAccount::Get_kamoku_l(int index,char *kamoku)
{
	//���o���S��
	int j;	long long kimatu=0;
	for(j=0;j<nkamoku;j++)
	{
		if(mem_km[j]->code==index){
			if(strcmp(mem_km[j]->kamoku,kamoku)==0)	kimatu=mem_km[j]->zandaka;
//			printf("xxxx1 j=%d n=%d k1=%d k2=%d  || %d\n",j,nkamoku,kimatu,strcmp(mem_km[j]->kamoku,kamoku));
		}
	}
	return kimatu;
}
int CAccount::Get_karikashi_ac(int index,char *kamoku)
{
	//���o���S��
	int j;	long long kimatu=0;
	for(j=0;j<nkamoku;j++)
	{
		if(mem_km[j]->code==index){
			if(strcmp(mem_km[j]->kamoku,kamoku)==0){ 
				kimatu=mem_km[j]->karikata_total-mem_km[j]->kashikata_total;
	//			printf("ki=%d kamoku=%s nkamoku=%d\n",mem_km[j]->zandaka,kamoku,j);
			}
		}
	}
	return int(kimatu);
}
int CAccount::Get_kisyu_ac(int index,char *kamoku)
{
	//���o���S��
	int j;	long long kimatu=0;
	for(j=0;j<nkamoku;j++)
	{
		if(mem_km[j]->code==index){
			if(strcmp(mem_km[j]->kamoku,kamoku)==0){ 
				kimatu=mem_km[j]->kisyu_zandaka;
	//			printf("ki=%d kamoku=%s nkamoku=%d\n",mem_km[j]->zandaka,kamoku,j);
			}
		}
	}
	return int(kimatu);
}
void CAccount::Erase_mem_sh()
{
	int i=0;
	int size_sh,size_shisan,size_keihi,size_husai,size_uriage,size_km,size_kmr;
	size_sh=mem_sh.size();
	size_shisan=mem_shisan_km.size();
	size_keihi=mem_keihi_km.size();
	size_husai=mem_husai_km.size();
	size_uriage=mem_uriage_km.size();
	size_km=mem_km.size();
	size_kmr=mem_kmr.size();
//	printf("before s_sh=%d s_shisan=%d s_keihi=%d s_husai=%d s_uriage=%d s_km,s_kmr=%d \n",mem_sh.size(),mem_shisan_km.size(),mem_keihi_km.size(),mem_husai_km.size(),mem_uriage_km.size(),mem_km.size(),mem_kmr.size());
	i=mem_sh.size()-1;
	while(mem_sh.size()>0)
	{
		sh=mem_sh[i];
		mem_sh.pop_back();
		delete sh;
		i=i-1;
	}


//	printf("after s_sh=%d s_shisan=%d s_keihi=%d s_husai=%d s_uriage=%d s_km,s_kmr=%d \n",mem_sh.size(),mem_shisan_km.size(),mem_keihi_km.size(),mem_husai_km.size(),mem_uriage_km.size(),mem_km.size(),mem_kmr.size());
}
#endif