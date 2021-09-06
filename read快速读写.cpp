inline int read()//inline 加速读入
{
	int x=0;char c=getchar();//x代表返回值，c代表读取的字符
	while (c<'0'||c>'9') c=getchar();//读取所有非数部分
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();//如果读取的字符为数，加入返回值
	return x;
}