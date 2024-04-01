/****************************************************************************
���ߣ�С�����Ѿ��
���ڣ�2020-6-19
�ļ�����FSM���״̬��ִ���ļ�
****************************************************************************/
/****************************************************************************
ͷ�ļ�
****************************************************************************/
#include "hsm.h"
/****************************************************************************
�궨��
****************************************************************************/

/****************************************************************************
����
****************************************************************************/

S_state_fun father_state[2] = {
    {F_Static_Init, F_Static_Keep, F_Satic_Done, F_Static_Default},
    {F_Run_Init, F_Run_Keep, F_Run_Done, F_Run_Default}}; //--����/����
S_state_fun childer_state[8] = {
    {C_Static_Set_Init, C_Static_Set_Keep, C_Satic_Set_Done, C_Static_Set_Default},
    {C_Static_Distribution_Network_Init, C_Static_Distribution_Network_Keep, C_Satic_Distribution_Network_Done, C_Static_Distribution_Network_Default},
    {C_Static_Shut_Down_Init, C_Static_Shut_Down_Keep, C_Satic_Shut_Down_Done, C_Static_Shut_Down_Default},
    {C_Static_Charge_Init, C_Static_Charge_Keep, C_Satic_Charge_Done, C_Static_Charge_Default},
    {C_Run_Normal_Init, C_Run_Normal_Keep, C_Run_Normal_Done, C_Run_Normal_Default},
    {C_Run_Dry_Init, C_Run_Dry_Keep, C_Run_Dry_Done, C_Run_Dry_Default},
    {C_Run_Besiege_Init, C_Run_Besiege_Keep, C_Run_Besiege_Done, C_Run_Besiege_Default},
    {C_Run_Avoid_Obstacles_Init, C_Run_Avoid_Obstacles_Keep, C_Run_Avoid_Obstacles_Done, C_Run_Avoid_Obstacles_Default}}; //--����1
E_father_states s_father_step = s_father_init;                                                                            //--���൥��״̬�ڲ�ת������
E_childer_states s_childer_step = s_childer_init;
E_hsm_father_state hsm_current_father_state = e_static_state; //--�����ʼ��
E_hsm_father_state hsm_last_father_state = e_static_state;
E_hsm_childer_state hsm_current_childer_state = e_set_state; //--�����ʼ��
E_hsm_childer_state hsm_last_childer_state = e_set_state;
/****************************************************************************
����
״̬������������
     �� �� C_Static_Set_Init
              C   ��  Static_   Set  _    Init
         �ã����� �ƣ�����������ĸ�������౾�����֣߸�����״̬�ڲ��׶�
****************************************************************************/
// int main(void)
// {
//     int update_cnt = 10;
//     int run_cnt = 1;
//     int cnt;
//     while (1)
//     {

//         if (update_cnt == 80)
//         {
//             hsm_current_father_state = 0;
//             hsm_current_childer_state = 0;
//         }
//         else if (update_cnt == 70)
//         {
//             hsm_current_father_state = 0;
//             hsm_current_childer_state = 1;
//         }
//         else if (update_cnt == 60)
//         {
//             hsm_current_father_state = 0;
//             hsm_current_childer_state = 2;
//         }
//         else if (update_cnt == 50)
//         {
//             hsm_current_father_state = 0;
//             hsm_current_childer_state = 3;
//         }
//         else if (update_cnt == 40)
//         {
//             hsm_current_father_state = 1;
//             hsm_current_childer_state = 4;
//         }
//         else if (update_cnt == 30)
//         {
//             hsm_current_father_state = 1;
//             hsm_current_childer_state = 5;
//         }
//         else if (update_cnt == 20)
//         {
//             hsm_current_father_state = 1;
//             hsm_current_childer_state = 6;
//         }
//         else if (update_cnt == 10)
//         {
//             hsm_current_father_state = 1;
//             hsm_current_childer_state = 7;
//         }
//         update_cnt--;
//         if (update_cnt == 0)
//         {
//             update_cnt = 80;
//         }
//         // LOG("hsm_current_father_state:%d hsm_current_childer_state:%d",hsm_current_father_state,hsm_current_childer_state);
//         //=================================����״̬��������=========================================
//         if (Father_State_Is_Allow_Jump())                                  //--���������ת
//             father_state[hsm_current_father_state].steps[s_father_step](); //--����״̬
//         else
//             father_state[hsm_last_father_state].steps[s_father_step](); //--����״̬
//                                                                         //==========================================================================
//     }
//     return 0;
// }
//--��״̬�Ƿ�������ת
uint8_t Childer_State_Is_Allow_Jump(void)
{
    if (s_childer_step == s_childer_init)
        return 1;
    else
        return 0;
}
//--��״̬�Ƿ�Ҫ����״̬ת��
uint8_t Is_Three_A_Childer_State_Transition(void)
{
    if (hsm_last_childer_state == hsm_current_childer_state)
        return 0;
    else
        return 1;
}
//--����״̬ת��
void Childer_State_Transition(E_hsm_childer_state temp)
{
    hsm_current_childer_state = temp;
}
//--���������һ��״̬
void Update_Childer_Last_State_Transition(void)
{
    hsm_last_childer_state = hsm_current_childer_state;
}
//--���൥��״̬�ڲ�ת��
void Childer_Step_Transition(E_childer_states temp)
{
    s_childer_step = temp;
}
//--��״̬�Ƿ�������ת
uint8_t Father_State_Is_Allow_Jump(void)
{
    if (s_father_step == s_father_init)
        return 1;
    else
        return 0;
}
//--��״̬�Ƿ�Ҫ����״̬ת��
uint8_t Is_Three_A_Father_State_Transition(void)
{
    if (hsm_last_father_state == hsm_current_father_state)
        return 0;
    else
        return 1;
}
//--����״̬ת��
void Father_State_Transition(E_hsm_father_state temp)
{
    hsm_current_father_state = temp;
}
//--���������һ��״̬
void Update_Father_Last_State_Transition(void)
{
    hsm_last_father_state = hsm_current_father_state;
}
//--����״̬�ڲ�ת��
void Father_Step_Transition(E_father_states temp)
{
    s_father_step = temp;
}
/*************************************************
 * ��ֹ״̬�����ࣩ
 * ���뺯��
 * ���ֺ���
 * �˳�����
 * ������
 * *************************************************/
void F_Static_Init(void)
{
    Update_Father_Last_State_Transition();
    //---------------------
    //--�����
    LOG("===���ࣺ��ֹ״̬====���뺯��>>>>>>>>>>>>>>>>>>>>>");
    //--------------------
    Father_Step_Transition(s_father_keep);
}
void F_Static_Keep(void)
{
    //---------------------
    //--�����
    // LOG("===���ࣺ��ֹ״̬====���ֺ���--------------------");
    //==========����״̬��������======================
    if (Childer_State_Is_Allow_Jump()) //--���������ת
    {
        //--��������������ת�������Ѿ�������ת��׼�������Ǹ��໹δ������ת��׼������ʱ��ִ��������ת
        if (Is_Three_A_Father_State_Transition())
        {
            Father_Step_Transition(s_father_done);
            return;
        }
        else
            Father_Step_Transition(s_father_keep);
        childer_state[hsm_current_childer_state].steps[s_childer_step](); //--����״̬
    }
    else
        childer_state[hsm_last_childer_state].steps[s_childer_step](); //--����״̬
    //--------------------
}
void F_Satic_Done(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ��ֹ״̬====�˳�����<<<<<<<<<<<<<<<<<<<<<<<<");
    //--------------------
    //--�ڲ��л�
    Father_Step_Transition(s_father_init);
}
void F_Static_Default(void)
{
    ;
}
/*************************************************
 * ����״̬�����ࣩ
 * ���뺯��
 * ���ֺ���
 * �˳�����
 * ������
 * *************************************************/
void F_Run_Init(void)
{
    Update_Father_Last_State_Transition();
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���뺯��>>>>>>>>>>>>>>>>>>>>>>>>>>");
    //--------------------
    Father_Step_Transition(s_father_keep);
}
void F_Run_Keep(void)
{
    //---------------------
    //--�����
    // LOG("===���ࣺ����״̬====���ֺ���--------------------");
    //==========����״̬��������======================
    if (Childer_State_Is_Allow_Jump()) //--���������ת
    {
        //--��������������ת�������Ѿ�������ת��׼�������Ǹ��໹δ������ת��׼������ʱ��ִ��������ת
        if (Is_Three_A_Father_State_Transition())
        {
            Father_Step_Transition(s_father_done);
            return;
        }
        else
            Father_Step_Transition(s_father_keep);
        childer_state[hsm_current_childer_state].steps[s_childer_step](); //--����״̬
    }
    else
        childer_state[hsm_last_childer_state].steps[s_childer_step](); //--����״̬
}
void F_Run_Done(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====�˳�����<<<<<<<<<<<<<<<<<<<<<<");
    //--------------------
    //--�ڲ��л�
    Father_Step_Transition(s_father_init);
}
void F_Run_Default(void)
{
    ;
}
/*************************************************
 * ����״̬�����ࣩ������ֹ�����ࣩ
 * ���뺯��
 * ���ֺ���
 * �˳�����
 * ������
 * *************************************************/
void C_Static_Set_Init(void)
{
    Update_Childer_Last_State_Transition();
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���뺯��>>>");
    //--------------------
    Childer_Step_Transition(s_childer_keep);
}
void C_Static_Set_Keep(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���ֺ���");
    //--------------------
    if (Is_Three_A_Childer_State_Transition())
        Childer_Step_Transition(s_childer_done);
    else
        Childer_Step_Transition(s_childer_keep);
}
void C_Satic_Set_Done(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====�˳�����<<<");
    //--------------------
    //--�ڲ��л�
    Childer_Step_Transition(s_childer_init);
}
void C_Static_Set_Default(void)
{
    ;
}
/*************************************************
 * ����״̬�����ࣩ������ֹ�����ࣩ
 * ���뺯��
 * ���ֺ���
 * �˳�����
 * ������
 * *************************************************/
void C_Static_Distribution_Network_Init(void)
{
    Update_Childer_Last_State_Transition();
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���뺯��>>>");
    //--------------------
    Childer_Step_Transition(s_childer_keep);
}
void C_Static_Distribution_Network_Keep(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���ֺ���");
    //--------------------
    if (Is_Three_A_Childer_State_Transition())
        Childer_Step_Transition(s_childer_done);
    else
        Childer_Step_Transition(s_childer_keep);
}
void C_Satic_Distribution_Network_Done(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====�˳�����<<<");
    //--------------------
    //--�ڲ��л�
    Childer_Step_Transition(s_childer_init);
}
void C_Static_Distribution_Network_Default(void)
{
    ;
}
/*************************************************
 * ����״̬�����ࣩ������ֹ�����ࣩ
 * ���뺯��
 * ���ֺ���
 * �˳�����
 * ������
 * *************************************************/
void C_Static_Shut_Down_Init(void)
{
    Update_Childer_Last_State_Transition();
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���뺯��>>>");
    //--------------------
    Childer_Step_Transition(s_childer_keep);
}
void C_Static_Shut_Down_Keep(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���ֺ���");
    //--------------------
    if (Is_Three_A_Childer_State_Transition())
        Childer_Step_Transition(s_childer_done);
    else
        Childer_Step_Transition(s_childer_keep);
}
void C_Satic_Shut_Down_Done(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====�˳�����<<<");
    //--------------------
    //--�ڲ��л�
    Childer_Step_Transition(s_childer_init);
}
void C_Static_Shut_Down_Default(void)
{
    ;
}

/*************************************************
 * ���״̬�����ࣩ������ֹ�����ࣩ
 * ���뺯��
 * ���ֺ���
 * �˳�����
 * ������
 * *************************************************/

void C_Static_Charge_Init(void)
{
    Update_Childer_Last_State_Transition();
    //---------------------
    //--�����
    LOG("===���ࣺ���״̬====���뺯��>>>");
    //--------------------
    Childer_Step_Transition(s_childer_keep);
}
void C_Static_Charge_Keep(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ���״̬====���ֺ���");
    //--------------------
    if (Is_Three_A_Childer_State_Transition())
        Childer_Step_Transition(s_childer_done);
    else
        Childer_Step_Transition(s_childer_keep);
}
void C_Satic_Charge_Done(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ���״̬====�˳�����<<<");
    //--------------------
    //--�ڲ��л�
    Childer_Step_Transition(s_childer_init);
}
void C_Static_Charge_Default(void)
{
    ;
}

/*************************************************
 * ����״̬�����ࣩ�������У����ࣩ
 * ���뺯��
 * ���ֺ���
 * �˳�����
 * ������
 * *************************************************/
void C_Run_Normal_Init(void)
{
    Update_Childer_Last_State_Transition();
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���뺯��>>>");
    //--------------------
    Childer_Step_Transition(s_childer_keep);
}
void C_Run_Normal_Keep(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���ֺ���");
    //--------------------
    if (Is_Three_A_Childer_State_Transition())
        Childer_Step_Transition(s_childer_done);
    else
        Childer_Step_Transition(s_childer_keep);
}
void C_Run_Normal_Done(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====�˳�����<<<");
    //--------------------
    //--�ڲ��л�
    Childer_Step_Transition(s_childer_init);
}
void C_Run_Normal_Default(void)
{
    ;
}
/*************************************************
 * ����״̬�����ࣩ�������У����ࣩ
 * ���뺯��
 * ���ֺ���
 * �˳�����
 * ������
 * *************************************************/
void C_Run_Dry_Init(void)
{
    Update_Childer_Last_State_Transition();
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���뺯��>>>");
    //--------------------
    Childer_Step_Transition(s_childer_keep);
}
void C_Run_Dry_Keep(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���ֺ���");
    //--------------------
    if (Is_Three_A_Childer_State_Transition())
        Childer_Step_Transition(s_childer_done);
    else
        Childer_Step_Transition(s_childer_keep);
}
void C_Run_Dry_Done(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====�˳�����<<<");
    //--------------------
    //--�ڲ��л�
    Childer_Step_Transition(s_childer_init);
}
void C_Run_Dry_Default(void)
{
    ;
}
/*************************************************
 * ����״̬�����ࣩ�������У����ࣩ
 * ���뺯��
 * ���ֺ���
 * �˳�����
 * ������
 * *************************************************/
void C_Run_Besiege_Init(void)
{
    Update_Childer_Last_State_Transition();
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���뺯��>>>");
    //--------------------
    Childer_Step_Transition(s_childer_keep);
}
void C_Run_Besiege_Keep(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���ֺ���");
    //--------------------
    if (Is_Three_A_Childer_State_Transition())
        Childer_Step_Transition(s_childer_done);
    else
        Childer_Step_Transition(s_childer_keep);
}
void C_Run_Besiege_Done(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====�˳�����<<<");
    //--------------------
    //--�ڲ��л�
    Childer_Step_Transition(s_childer_init);
}
void C_Run_Besiege_Default(void)
{
    ;
}
/*************************************************
 * ����״̬�����ࣩ�������У����ࣩ
 * ���뺯��
 * ���ֺ���
 * �˳�����
 * ������
 * *************************************************/
void C_Run_Avoid_Obstacles_Init(void)
{
    Update_Childer_Last_State_Transition();
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���뺯��>>>");
    //--------------------
    Childer_Step_Transition(s_childer_keep);
}
void C_Run_Avoid_Obstacles_Keep(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====���ֺ���");
    //--------------------
    if (Is_Three_A_Childer_State_Transition())
        Childer_Step_Transition(s_childer_done);
    else
        Childer_Step_Transition(s_childer_keep);
}
void C_Run_Avoid_Obstacles_Done(void)
{
    //---------------------
    //--�����
    LOG("===���ࣺ����״̬====�˳�����<<<");
    //--------------------
    //--�ڲ��л�
    Childer_Step_Transition(s_childer_init);
}
void C_Run_Avoid_Obstacles_Default(void)
{
    ;
}