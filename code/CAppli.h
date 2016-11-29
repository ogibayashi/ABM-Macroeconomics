//CAppli.h
#ifndef INC_CAPPLICATIONS
#define INC_CAPPLICATIONS
#include <stdio.h>
#include <vector>
#include "CMarket.h"
#include "CShow.h"
#include "CParameter.h"
#include "CVector_owner.h"
#include "CFunction.h"
//#include "CAccount.h"
using namespace std;

class CAppli
{
	public:
	CMarket *cm;
	CShow *cs;
	CParameter *cpara;
	CVector_owner *cvo;
	CFunction *cf;
	int Agent_type;
			//Agent_type=10; ��ʏ����
			//Agent_type=20; ��ʏ���Ҍ������Y��
			//Agent_type=30; ���Y�Ҍ������Y�ҁi�����𐶎Y)
			//Agent_type=40; ���Y�Ҍ������Y�ҁi�ݔ����g�[)
			//Agent_type=50; ��s
	int nconsumer;		//��ʏ���҂̐�
	int nretailer;		//��ʏ���Ҍ������Y��
	int nwholesaler;	//���Y�Ҍ������Y�ҁi�����𐶎Y����)
	int nequipment;		//�ݔ������Ґ�
	int nbank;			//��s��
	int n_class;		//�s��ɂ��鐻�i��ʂ̍ő吔
						//���i��ʔԍ���1����n_class�̐�
	int qmaxmax;		//���Y�҂̐��Y�\�͂̍ő�l
	int qmaxmin;		//���Y�҂̐��Y�\�͂̍ŏ��l
	int qmaxmax_w;		//�z�[���Z���[�̐��Y�\�͂̍ő�l
	int qmaxmin_w;		//�z�[���Z���[�̐��Y�\�͂̍ŏ��l
	int period_max;			//����
	int nbonus;			//nbonus=0 when without bonus
						//nbonus=1 half bonus
						//nbonus=2 when with bonus
	int max_ban;//�ő�p�Ǝw��

	int genkin_kisyu_zandaka; int yokin_kisyu_zandaka;	int loan_kisyu_zandaka;


	/////////////�v�Z���ʏ������ݗp�t�@�C���̐錾//////////////////


///////////////////�p�����[�^���͗p�t�@�C���錾//////////////////////

	

	void Set_Parameter();	//�����p�����[�^�̐ݒ�
	void Create_Agent();	//�G�[�W�F���g�N���X�̐���
	void Create_Market(){cs=new CShow; cm=new CMarket(cs);};		//�}�[�P�b�g�N���X�̐���
	void Create_file();		//�������ݗp�t�@�C���̏����ݒ�

	void Market();
	void Write_periodfast(int i);//�����̉��s�A�����\���̓��͊֐�
	void Show_member_renew();	//show�̃����o�[�̃A�h���X���X�V����
	void Create_Assumption(){cpara=new CParameter;	};	//�p�����[�^�N���X�̐���

	void Labor_limit_up(int i);
	void Labor_kimatu(int i);
	void Labor_gov_yosan(int i);
};


void CAppli::Set_Parameter()
{
	//CParameter��CSV�t�@�C���ǂݍ���
	cpara->FILE_set_parameter();	//CParameter���Ńp�����[�^�t�@�C����ǂݍ���

	//CAppli���ł̎g�p����ϐ��i�����Ă���CMarket���֐��̈����Ŏg�p�j
	nconsumer	=	cpara->GET_PARA_nconsumer();	
	nretailer	=	cpara->GET_PARA_nretailer();	
	nwholesaler	=	cpara->GET_PARA_nwholesaler();	
	n_class	=	cpara->GET_PARA_n_class();			
	qmaxmax	=	cpara->GET_PARA_qmaxmax();			
	qmaxmax_w	=	cpara->GET_PARA_qmaxmax_w();	
	period_max	=	cpara->GET_PARA_period_max();	
	nbonus	=	cpara->GET_PARA_nbonus();			
	max_ban	=	cpara->GET_PARA_max_ban();			
	nbank	=	cpara->GET_PARA_nbank();	
	nequipment	=	cpara->GET_PARA_nequipment();
	qmaxmin	=	cpara->GET_PARA_qmaxmin();
	qmaxmin_w	=	cpara->GET_PARA_qmaxmin_w();
}

void CAppli::Create_file()
{
	cpara->FILE_set_printfile();	//////�t�@�C���̃I�[�v��//////////
	cm->Set_Parameter_class(cpara);	//CMarket�N���X��CParameter�̃|�C���^�����n��
	cm->Set_seed();
	cs->Set_Parameter_class(cpara);	//CShow��CParameter�̃|�C���^�����n��
	cm->Set_FILE_output();			//CMarket�N���X��CParameter�N���X����t�@�C���A�h���X���擾
	cs->Set_output_FILE();			//CShow�N���X��CParameter�N���X����t�@�C���A�h���X���擾
}

void CAppli::Write_periodfast(int i)
{
	cs->Write_periodfast(i);	//����t�@�C���v�����g�p�i�������j

	cs->set_consumer_add(cm->PrintDataGet_consumer_add());
	cs->set_retailer_add(cm->PrintDataGet_Retailer_add());
	cs->set_wholesaler_add(cm->PrintDataGet_Wholesaler_add());
	cs->set_equipment_add(cm->PrintDataGet_Equipment_add());
	cs->set_bank_add(cm->PrintDataGet_Bank_add());
	cs->set_government_add(cm->PrintDataGet_Governament());
	cs->Set_i_period(i);		//CShow�N���X���Ɋ�������
	printf("�����F%d\n",i);
}
void CAppli::Show_member_renew()
{
	cs->set_consumer_add(cm->PrintDataGet_consumer_add());
	cs->set_retailer_add(cm->PrintDataGet_Retailer_add());
	cs->set_wholesaler_add(cm->PrintDataGet_Wholesaler_add());
	cs->set_equipment_add(cm->PrintDataGet_Equipment_add());
	cs->set_bank_add(cm->PrintDataGet_Bank_add());
	cs->set_government_add(cm->PrintDataGet_Governament());
}


void CAppli::Create_Agent()
{


	//////�����l�̐ݒ�//////	////////��v��������p//////
	cm->Set_parameter();	//CMarket�N���X����CParameter���炷�ׂĂ̎g�p�֐��̏����p�����[�^���

	
	///////�G�[�W�F���g�̐���////////
	cm->CReate_Government();//�s���G�[�W�F���g�̐���
	cm->CReate_Bank(nbank);//��s�I�u�W�F�N�g�̏����l�ݒ�
	cm->CReate_Wholesaler(nwholesaler);//Agent_no=1,....,nwholesaler�𐶐�	
				//�ewholesaler���ɐ��Y���i��ʐ�ncr_p���`���Ancr_p��Product_class�̃C���X�^���Xmem_class_p�𐶐�����
				//ncr_p�̐��i��ʃC���X�^���X�ɐ��i��ʔԍ����������
				//�������Y�ʂ͖���`
	cm->Set_qmax_whole(qmaxmax_w,qmaxmin_w);//�z�[���Z���[�̐��Y�\�͂̍ő�l�̐ݒ�iqmaxmax_w)
				//�e���i��ʖ��ɏ������Y��q,q_init�̌���iint(0.5*qmax)�`qmax�̗���)
				// q_limit;//���Y�����(�������Y�ʁjq_limit_d;//���Y�������̐ݒ�(q_limit*0.5)


	cm->CReate_Retailer(nretailer);//Agent_no=nwholesaler+1,...nwholesaler+nretailer�𐶐�
				//ncr_p��Product_class�̃C���X�^���X�𐶐����Amem_class_p�Ɋi�[����
				//ncr_p�̐��i��ʃC���X�^���X�ɐ��i��ʔԍ����������
	cm->Set_qmax_retailer(qmaxmax,qmaxmin);//���e�C���[�̐��Y�\�͂̍ő�l�̐ݒ�,���̒��ŏ����̐��Y�ʂ�����
							 //�����̐��Y�\�͂͊F�����A���Y�ʂ�0.5qmx�`qmx�̊Ԃŗ����Ō���
	fprintf(cpara->FI_Get_out(),"Before Create Equipment\n");
	cm->Create_Equipment(nequipment);	//�ݔ��̔���Ёi�P�ЁjAgent_no=nwholesaler+nretailer+1
										//Agent_no=nwholesaler+nretailer+1,....nwholesaler+nretailer+nconsumer�𐶐�
	cm->CReate_Consumer(nconsumer);		//Consumer�̐���
	cm->Employ(nconsumer);				//Consumer���]�ƈ��Ƃ���producer�֔z������
//	cm->Set_init_equipment_revel();		//��Ƃ̐ݔ����x���̏����ݒ�
	cm->Inv_set_init_equipment_level();
	cm->Cobb_Duclas_production_func();	//�ݔ����x���ƘJ���҂��琶�Y�ʂ�����

	cs->show_income();					//cm->show_income();//����҂�income��se_con�ɕ\�����Aproducer_type�ʂ̍��v��se_income�ɕ\������										
	cs->Show_employ();					//�v�����g�p�f�[�^�󂯓n��

	cm->Create_CSpace();				//�����Ԃ̃I�u�W�F�N�g�����A�y��Parameter,Show�̈����n��


}


void CAppli::Market()
{
	int i;
	

	for(i=0;i<period_max;i++)
	{
		fprintf(cpara->FI_Get_all_money(),"���� , ");cm->Print_allmoney();

		cm->Labor_housyu();					//������V���胍�W�b�N
		
		fprintf(cpara->FI_Get_all_money(),"����2, ");cm->Print_allmoney();
		if(i==cpara->Get_PARA_change_time())
		{
			switch(cpara->Get_PARA_tax_change_switch())
			{
			case 0:

				break;

			case 1:
				cpara->change_income_tax_rate();
				cpara->change_e_flag();
				break;

			case 2:
				cpara->change_corp_tax_rate();
				cpara->change_e_flag();
				break;
			}
			
		}

		fprintf(cpara->FI_Get_phenom_writer(),"\n-------------------%d���X�^�[�g-------------\n\n",i);
		printf("-------------------%d���J�n-------------------\n",i);
		Write_periodfast(i);		//�����̉��s�A�����\���̓��͊֐�
		cm->Set_i_period(i);//�����̃}�[�P�b�g�ւ̓���
		cm->Kisyu();		//�����v����
		fprintf(cpara->FI_Get_all_money(),"���񏈗��� , ");cm->Print_allmoney();
		///���{�s��1�\�Z����
		Labor_gov_yosan(i);
		fprintf(cpara->FI_Get_all_money(),"���Y�O , ");cm->Print_allmoney();
		//�`�`�`�`�`�`�`�`���Y���� Pro�`�`�`�`�`�`�`�`�`
		if(i==0)
		{
			cm->Labor_choice_producer();
			//cm->Labor_Reset_limit_up_data();
			printf("�����J�n\n");
			cm->Production_whole();
			//���Y���鐻�i��ʖ��ɉ��i�����肷��
			//�e���i��ʂɂ��Đ��i��q���B�e���Y�҂̐��i���e���Y�҂̑q��(mem_product_whole)�Ɋi�[����
			cm->Define_mem_ncr_w();//wholesaler�̐��i��ʔԍ��̏W�����`����
			//cm->Show_mem_ncr_w();//��̕\��
			cm->Define_mem_ncr_r();//retailer�̐��i��ʔԍ��̏W��=consusmer���w�����鐻�i��ʔԍ��̏W�����`����
			//cm->Show_mem_ncr_r();//��̕\��
			cm->Define_seizou();
			//���i��ʖ���mem_ncr_w�̒����猴���������_���ɂP�w�肷��B
			cm->Production_retail();
			//�e���i��ʖ��ɐ��Y��q�A���iprice�����肵�A�e���i��ʂɂ��Đ��i��q���B�e���Y�҂̐��i���s��̑q��(mem_product)�ɂ����
			cm->Create_price_tag();

			//Show�p�x�N�^�[�󂯓n��
			cs->set_mem_buy(cm->PrintDataGet_mem_buy());					//CS:�w�������x�N�^�]��	
			cs->set_mem_buy_w(cm->PrintDataGet_mem_buy_w());				//CS:�w�������x�N�^W��]��
			cs->set_mem_product(cm->PrintDataGet_mem_product());			//CS:���i�x�N�^�]��
			cs->set_mem_product_w(cm->PrintDataGet_mem_product_whole());	//CS:���i�x�N�^W��]��
			cs->set_mem_ncr_r(cm->PrintdataGet_mem_ncr_r());				//CS:ncr_r��]��
			cs->set_mem_ncr_w(cm->PrintDataGet_mem_ncr_w());				//CS:ncr_w��]��

			cs->Show_mem_ncr_w();
			cs->Show_mem_ncr_r();
		}
		else
		{
			printf("�����J�n\n");
			cm->Production_whole_revised();
			fprintf(cpara->FI_Get_all_money(),"W���Y�� , ");cm->Print_allmoney();
			cm->Production_retail_revised();	//�����w��
			fprintf(cpara->FI_Get_all_money(),"R���Y�� , ");cm->Print_allmoney();
			cs->set_mem_buy_w(cm->PrintDataGet_mem_buy_w());				//CS:�w�������x�N�^��CS�ɓ]��
			cs->set_mem_product(cm->PrintDataGet_mem_product());			//CS:���i�x�N�^��CS�ɓ]��
			cs->set_mem_product_w(cm->PrintDataGet_mem_product_whole());	//CS:���i�x�N�^_W��CS�ɓ]��
		}
		printf("�����I��\n");
		//�`�`�`�`�`�`�`�`�`���Y�����I�� Pro�`�`�`�`�`�`�`
		fprintf(cpara->FI_Get_all_money(),"���Y�� , ");cm->Print_allmoney();

		//�`�`�`�`�`�`���Y������󋵕\���`�`�`�`�`�`�`�`
		cs->Show_test_2(i);	//���i��ʐ��Y��
		cs->Show_retailer();
		//producer no,���i��ʐ��A���i��ʔԍ��A���ꂼ��̐��Y�ʁA������ı�Ă���
		//�������i���Y�ʂ͖���,���i�͌���ς�,price=cost*alpha;
		//fprintf(producer_no,"%d",i); cm->Show_producer_no();
		cs->Show_product_class();//���i��ʂ��Ƃɐ��i�̔ԍ��A���i�A�����Ҕԍ����v�����g�A�E�g����B
		fprintf(cpara->FI_Get_out(),"consumer �̍w�����鐻�i��ʔԍ��̒�` in Set_class_no_c\n");//file�o��;
	//	cs->Show_balance();//�s���O�܂����			

		//�`�`�`�`�`�`���Y������󋵕\���I���`�`�`�`�`�`�`�`


		cm->Set_reserve();//�����������ݒ�//����������O

		
		//�`�`�`�`�`�`�`�`�w������ B�`�`�`�`�`�`�`�`
		cm->Calc_R_koubai_yosan();
		printf("�w���J�n\n");
		cm->Buy_consumer();		//�S�Ă̏���҂����������͈͓̔��ōŒቿ�i�̐��i���w������B
		cm->buy_checker();
fprintf(cpara->FI_Get_free_text2(),"�����\n");		cm->Buy_government();	//���{�w��
fprintf(cpara->FI_Get_free_text2(),"���{\n");		cm->Buy_producer();		//���e�C���[�A�z�[���Z���[�̎s��w��
fprintf(cpara->FI_Get_free_text2(),"���\n");		printf("�w���I��\n");

		
		fprintf(cpara->FI_Get_all_money(),"�w���� , ");cm->Print_allmoney();

		//�`�`�`�`�`�`�w�������I���`�`�`�`�`�`�`�`�`�`

		cs->set_mem_product(cm->PrintDataGet_mem_product());			//CS:���i�x�N�^��CS�ɓ]��
		cs->set_mem_buy(cm->PrintDataGet_mem_buy());					//CS:�w�������x�N�^�]��	
		cs->Show_bought_product_class();	fprintf(cpara->FI_Get_out(),"����c�菤�i���X�g\n");
		cs->Show_product_class();
		cs->Show_test(i);//���i��ʍ݌�
//		fprintf(cpara->FI_Get_product_price(),"%d,",i);
		cm->Def_statics_mem_buy();		//cm->Show_statics_mem_buy();
		cs->set_mem_class_statics(cm->PrintDataGet_mem_class_statics());//CS:���i��󋵃x�N�^�iR)��]��
		cs->Show_statics_mem_buy();

		cm->Def_statics_mem_product();//����c�菤�i�̓��v�f�[�^�̒�`
		cs->set_mem_class_stock_statics(cm->PrintDataGet_mem_class_stock_statics());	//CS:���i��ʍ݌ɏ󋵃x�N�^�iR)��]��
		cs->set_mem_class_stock_statics_w(cm->PrintDataGet_mem_class_stock_statics_w());//CS:���i��ʍ݌ɏ󋵃x�N�^�iW)��]��
		cs->Show_statics_mem_product();
		cs->Show_termly_change(i);
		cm->Clear_p_class_buy();//�����w�����ꂽ���i���̋L���w�ւ̈ڂ��ς��ƕۗL
		cs->set_mem_class_statics_w(cm->PrintDataGet_mem_class_statics_w());	//CS:���i��󋵃x�N�^�iW�j��]��
		if(i>=1)cs->Show_static_mem_buy_w();	//cm->Show_static_mem_buy_w();
		fprintf(cpara->FI_Get_out(),"retailer���̃N���X�ʎs�ꓝ�v�f�[�^�̕\��\n");
		cm->Show_statics_retailer();//producer�ɓ��v���f�[�^���󂯓n���A�����\������
	    //���̎��_��mem_class_p�ɓ��v�f�[�^�����͂����
		fprintf(cpara->FI_Get_out(),"retailer�̍݌ɏ��\n");
		cm->Def_nstock_retailer(); 
	
		cm->Erase_mem_statics_w();
		cm->Clear_p_class_buy_w();
	
		cm->Agent_hensai();//�eR,W,E�̒Z���ԍύs��
		printf("�f�[�^�W�v�I��\n");
		fprintf(cpara->FI_Get_all_money(),"�f�[�^�W�v�� , ");cm->Print_allmoney();

		////���^�x�����s��//
		cm->Suply_pay_wage();
		fprintf(cpara->FI_Get_all_money(),"���^�x������ , ");cm->Print_allmoney();
		cm->Labor_situgyouhosyou();
		fprintf(cpara->FI_Get_all_money(),"���ƕ⏞�� , ");cm->Print_allmoney();
		cm->Sort_income();			//���^�̃\�[�g
		printf("�����I��\n");

		
		/////���{����////////
		cm->Cobb_Duclas_production_func();
		cm->Hosyou_shouhisya_kouhukin();	//�n�R�l�D��
		


		Labor_limit_up(i); //���Y�\�͊g��n�@�p�����[�^�I�����̂��ߕʊ֐��ړ�
		fprintf(cpara->FI_Get_all_money(),"�g��� , ");cm->Print_allmoney();

		if(cpara->Get_PARA_Labor_assignment_switch()==0)
		{
			switch(cpara->Get_PARA_Labor_hozyokin_switch())
			{
			case 0:
				cm->Hozyokin_kouhu();	//��ƕ⏕��
				break;
			case 1:
				cm->Labor_Hozyokin_kouhu();
				break;
			case 2:
				cm->Labor_Hozyokin_kouhu_zyoui();
				break;
			}
		}
		else if(cpara->Get_PARA_Labor_assignment_switch()==1)
		{
			cm->Labor_Hozyokin_kouhu_assignment();
		}
		printf("���{�I��\n");
		fprintf(cpara->FI_Get_all_money(),"�⏕����t�� , ");cm->Print_allmoney();

		/////��������////////
		Labor_kimatu(i);

		if(cpara->Get_PARA_Labor_recognition_riekiritu_switch()==1) cm->Labor_recognition_riekiritu();
		
		fprintf(cpara->FI_Get_all_money(),"���������� , ");cm->Print_allmoney();

		
		switch(cpara->Get_PARA_calc_gdp_switch())
		{
		case 0:
			cs->Show_gdp_buy_pro_not_gdp();
			break;
			
		case 1:
			cs->Show_gdp();
			break;
		}
		if(i==0)	cs->Show_rieki_loan_first();
		cs->Show_rieki_loan();	//�������v��]�ƒZ���ؓ��̕\��
		cs->Tyotikuprint();
		cs->Show_Zini();		//�W�j�W���v�Z

		cs->Show_print_data();	//aida//csv�o�͓���

		cs->Show_zikoshihonhiritu();
		cs->Show_market_product();
		cm->Erase_mem_buy();
		cm->Erase_mem_statics();
		cm->Erase_mem_stock_statics();
		cm->Show_tax();
		cm->Labor_Print_fixed_wage();
		cm->PrintProducer_yokin_suitoutyou();
		printf("-------------------%d���I��-------------------\n",i);
		fprintf(cpara->FI_Get_phenom_writer(),"\n-------------------%d���I��-------------\n\n",i);
		fprintf(cpara->FI_Get_all_money(),"�Ō� , ");cm->Print_allmoney();
		fprintf(cpara->FI_Get_all_money(),"\n");cm->Print_allmoney();

	}
}

void CAppli::Labor_gov_yosan(int i)
{
	switch(cpara->Get_PARA_Labor_limit_up_type_switch())
	{
	case 0:				//���f��@�����	&�@�g����@�@�ݔ��̂݁@�i��ESSA���[���j
		cm->Gav_yosan();
		break;

	case 1:				//���f��@������@	&�@�g����@�@�ݔ��ƌٗp�@�`�`�`����͌��ݗ��p�s�`�`�`
		
		break;

	case 2:				//���f��@���v		&�@�g����@�@�ݔ��̂�
		cm->Gav_yosan();
		break;

	case 3:				//���f��@���v		&�@�g���@�@�ݔ��ٗp

		cm->Labor_government_yosan();
		break;

	}

}

void CAppli::Labor_limit_up(int i)
{
	
	switch(cpara->Get_PARA_Labor_limit_up_type_switch())
	{
	case 0:				//���f��@�����	&�@�g����@�@�ݔ��̂݁@�i��ESSA���[���j
		cm->Investment();		
		cm->Cobb_Duclas_production_func();	
		break;

	case 1:				//���f��@������@	&�@�g����@�@�ݔ��ƌٗp�@�`�`�`����͌��ݗ��p�s�`�`�`

		break;

	case 2:				//���f��@���v		&�@�g����@�@�ݔ��̂�
				fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�m�F�Aeqw�̐��l�̕ω��m�F��`�`�`\n\n");
		cm->Labor_print_eqw();

		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�ӎv����`�`�`\n\n");
		cm->Inv_labor_decide_inv_not_emp();
		printf("decide_emp_inv_end\n");
		

		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�ٗp�`�`�`\n\n");
//		cm->Labor_Recruitment_activity();
		printf("recrutiment_end\n");
//fprintf(cpara->FI_Get_employ(),"01 : ");cs->Show_employ_c();

		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�m�F�Aeqw�̐��l�̕ω��m�F��`�`�`\n\n");
		cm->Labor_print_eqw();

		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�ݔ������`�`�`\n\n");
		cm->Labor_Investment();
		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�m�F�Aeqw�̐��l�̕ω��m�F��`�`�`\n\n");
		cm->Labor_print_eqw();

		cm->Cobb_Duclas_production_func();	
	
		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`%d���ڏ����㐶�Y�\�́`�`�`\n\n\n",i);
		cm->Labor_print_production_power();
		fprintf(cpara->FI_Get_Labor_writer(),"\n\n\n\n�`�`�`%d���ڏ����I���`�`�`\n\n\n",i);
		cm->Labor_Reset_limit_up_data();
		break;

	case 3:				//���f��@���v		&�@�g���@�@�ݔ��ٗp
	
		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�m�F�Aeqw�̐��l�̕ω��m�F��`�`�`\n\n");
		cm->Labor_print_eqw();

		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�ӎv����`�`�`\n\n");
		cm->Inv_labor_decide_emp_inv();
		
		printf("decide_emp_inv_end\n");
		
		

		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�ٗp�`�`�`\n\n");
		cm->Labor_Recruitment_activity();

		printf("recrutiment_end\n");
//fprintf(cpara->FI_Get_employ(),"01 : ");cs->Show_employ_c();

		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�m�F�Aeqw�̐��l�̕ω��m�F��`�`�`\n\n");
		cm->Labor_print_eqw();
		
		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�ݔ������`�`�`\n\n");
		cm->Labor_Investment();
		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`�m�F�Aeqw�̐��l�̕ω��m�F��`�`�`\n\n");
		
		
		
		cm->Labor_print_eqw();

		cm->Cobb_Duclas_production_func();	
	
		fprintf(cpara->FI_Get_Labor_writer(),"\n\n�`�`�`%d���ڏ����㐶�Y�\�́`�`�`\n\n\n",i);
		cm->Labor_print_production_power();
		fprintf(cpara->FI_Get_Labor_writer(),"\n\n\n\n�`�`�`%d���ڏ����I���`�`�`\n\n\n",i);
		cm->Labor_Reset_limit_up_data();


		break;
	}
}



void CAppli::Labor_kimatu(int i)
{
	switch(cpara->Get_PARA_Labor_limit_up_type_switch())
	{
	case 0:				//���f��@�����	&�@�g����@�@�ݔ��̂݁@�i��ESSA���[���j
		/////��������////////
		cm->Kimatu();//������v����
		cm->Bankruptcy(max_ban);//�|�Y����
		printf("�|�Y�I��\n");

		cm->Kessan_Agent();
		cm->Deposit_consumer();//����҂̑O���̋��^����̗a���s��
		cm->Dismiss();		//���ٍs��
		Show_member_renew();
		printf("���ُI��\n");
		break;

	case 1:				//���f��@������@	&�@�g����@�@�ݔ��ƌٗp�@�`�`�`����͌��ݗ��p�s�`�`�`

		break;

	case 2:				//���f��@���v		&�@�g����@�@�ݔ��̂�
		/////��������////////
		cm->Kimatu();//������v����
		cm->Bankruptcy(max_ban);//�|�Y����
		printf("�|�Y�I��\n");

		cm->Kessan_Agent();
		cm->Deposit_consumer();//����҂̑O���̋��^����̗a���s��
		cm->Dismiss();		//���ٍs��
		Show_member_renew();
		printf("���ُI��\n");
		cm->Dismiss();		//���ٍs��
		break;

	case 3:				//���f��@���v		&�@�g���@�@�ݔ��ٗp
		/////��������////////
		cm->Kimatu();//������v����
		cm->Labor_Bankruptcy(max_ban);
//		cm->Bankruptcy(max_ban);//�|�Y����
		printf("�|�Y�I��\n");
		cm->Kessan_Agent();
		cm->Deposit_consumer();//����҂̑O���̋��^����̗a���s��

		cm->Labor_Dismiss();	//���ٍs���@�p�����[�^�I�����̂��ߕʊ֐��ړ�

		Show_member_renew();
		printf("���ُI��\n");


		
		break;
	}
}


#endif