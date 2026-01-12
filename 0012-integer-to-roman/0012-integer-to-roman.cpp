class Solution {
public:
  string intToRoman(int sum) {        
	string ans ="";
	while(sum>=1000)
	{
		ans+='M';
		sum-=1000;
	}
	if(sum >= 900) { ans += "CM"; sum -= 900; }
	if(sum>=500)
	{
		ans+='D';
		sum-=500;
	}
	if(sum>=400)
	{
		ans+="CD";
		sum-=400;
	}
	while(sum>=100)
	{
		ans+='C';
		sum-=100;
	}
	if(sum >= 90) { ans += "XC"; sum -= 90; }
	if(sum>=50)
	{
		ans+='L';
		sum-=50;
	}
	if(sum>=40)
	{
		ans+="XL";
		sum-=40;
	}
	while(sum>=10)
	{
		ans+='X';
		sum-=10;
	}
	if(sum >= 9) { ans += "IX"; sum -= 9; }
	if(sum>=5)
	{
		ans+='V';
		sum-=5;
	}
	if(sum>=4)
	{
		ans+="IV";
		sum-=4;
	}
	while(sum>=1)
	{
		ans+='I';
		sum-=1;
	}
	return ans;
    }
};
