template<typename T1, typename T2> class Struct_Pair 
{
public:
	Struct_Pair() 
	{
		a = T1();
		b = T2();
	}
	Struct_Pair(T1 temp_a, T2 temp_b)
	{
		a = temp_a;
		b = temp_b;
	}
	~Struct_Pair()
	{
		~T1();
		~T2();
	}
private:
	T1 a;
	T2 b;
};