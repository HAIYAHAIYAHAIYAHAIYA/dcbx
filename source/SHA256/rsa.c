#include "main.h"
int changdu;
int c[100];
// 判断两个数是不是互素。
bool gcd(int p, int q)
{
	int temp1, temp2; // q=temp2*p+temp1 ;
	if (q < p)
	{
		temp1 = p;
		p = q;
		q = temp1;
	}
	temp1 = q % p, temp2 = q / p;
	while (temp1 != 0)
	{

		q = p;
		p = temp1;
		temp1 = q % p;
		temp2 = q / p;
	}
	if (temp1 == 0 && temp2 == q)
	{
		LOG("符合条件!\n");
		return true;
	}
	else
	{
		LOG("不符合条件!请重新输入:\n");
		return false;
	}
}

// 求e关于模(p-1)(q-1)的逆元d:即私钥
int extend(int e, int t)
{
	int d;
	for (d = 0; d < t; d++)
	{
		if (e * d % t == 1)
			return d;
	}
}

// 判断输入的p和q是不是素数
bool is_sushu(int s)
{
	for (int i = 2; i < s; i++)
	{
		if (s % i == 0)
			return false;
	}
	return true;
}
// 将明文转换成数字明文
// void convert(){
//	char mingwen[100];    //符号明文
//	LOG("请输入明文:\n");
//	gets(mingwen);
//	changdu=strlen();
//	int ming[changdu];   //定义符号明文
//	for(int i=0;i<changdu;i++){
//	ming[i]=mingwen[i];        //将字母转换成对应的ascii码。
//	LOG("%d",mingwen[i]);
//	}
//
//
// }

// 加密函数
void encrypt(int e, int n)
{ // 自己指定指数e

	// 先将符号明文转换成字母所对应的ascii码。
	char mingwen[100]; // 符号明文
	LOG("请输入明文:\n");
	scanf("%s", mingwen);
	// gets(mingwen);
	changdu = strlen(mingwen);
	int ming[strlen(mingwen)]; // 定义符号明文
	for (int i = 0; i < strlen(mingwen); i++)
	{
		ming[i] = mingwen[i];	  // 将字母转换成对应的ascii码。
		LOG("%d", mingwen[i]); // 将字母转换成对应的ascii码。可以不打印
	}
	LOG("\n");
	// 开始加密
	LOG("加密开始…………………………\n");
	int zhuan = 1; // c为加密后的数字密文
	for (int i = 0; i < strlen(mingwen); i++)
	{

		for (int j = 0; j < e; j++)
		{
			zhuan = zhuan * ming[i] % n;
			// zhuan=zhuan%n;
		}
		c[i] = zhuan;
		// LOG("%d",mi[i]);
		zhuan = 1;
	}
	LOG("加密密文为:\n");
	for (int i = 0; i < strlen(mingwen); i++)
		LOG("%d", c[i]);
	LOG("\n加密结束…………………………\n");
	// 以下写法会导致溢出!
	//	{
	//		for(int i=0;i<strlen(mingwen);i++){
	//		zhuan=pow()
	//		mi[i]=int(pow(ming[i],e))%n;
	//		LOG("密文为:%d",mi[0]);
	//	}
	//	}

	//	LOG("密文为:\n");
	//	for(int i=0;i<strlen(mingwen);i++){
	//		LOG("%d",mi[i]);
	//	}
}

// 解密函数
void decrypto(int d, int n)
{
	int de_mingwen[changdu], zhuan1 = 1;
	char de_ming[changdu];
	for (int i = 0; i < changdu; i++)
	{

		for (int j = 0; j < d; j++)
		{
			zhuan1 = zhuan1 * c[i] % n;
			// zhuan=zhuan%n;
		}
		de_mingwen[i] = zhuan1;
		// LOG("%d",mi[i]);
		zhuan1 = 1;
	}
	LOG("解密开始…………………………\n");
	LOG("解密后的数字明文为:\n");
	for (int i = 0; i < changdu; i++)
		LOG("%d", de_mingwen[i]);
	LOG("\n");
	LOG("解密后的符号明文为:\n");
	for (int i = 0; i < changdu; i++)
	{
		de_ming[i] = de_mingwen[i];
		LOG("%c", de_ming[i]);
	}
	LOG("\n解密结束…………………………\n");
}

int rsa_test(void)
{
	int q, p, e, d, n, t, x, tep;
	while (1)
	{
		LOG("请输入p:", p);
		scanf("%d", &p);
		tep = is_sushu(p);
		if (tep == 0)
		{
			LOG("p不是素数,请重新输入p!\n");
			continue;
		}
		LOG("请输入q:", q);
		scanf("%d", &q);
		tep = is_sushu(q);
		if (tep == 0)
		{
			LOG("q不是素数,请重新输入q!\n");
			LOG("请输入q:", q);
			scanf("%d", &q);
			tep = is_sushu(q);
		}
		n = q * p;
		t = (q - 1) * (p - 1);
		tep = gcd(p, q);
		if (tep == 0)
			continue;
		LOG("t=(q-1)*(p-1)=%d", t);
		LOG("请输入一个指数e,使得(e,t)=1\n");
		scanf("%d", &e);
		tep = gcd(e, t);
		while (tep == 0)
		{
			LOG("请重新输入一个指数e,使得(e,t)=1:");
			scanf("%d", &e);
			tep = gcd(e, t);
		}
		d = extend(e, t);
		LOG("密钥为:%d,一定保管好!", d);
		LOG("\n\n-----------------------------------------------------------\n");
		encrypt(e, n);
		LOG("\n请输入正确的密钥,密钥正确将解密上面的密文:");
		scanf("%d", &d);
		decrypto(d, n);
		LOG("\n-----------------------------------------------------------\n");
	}

	return 0;
}