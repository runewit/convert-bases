#include <stdio.h>
#include <string.h>

int power(int a, int b){
	int i, sum=1;
	for(i=b;i>0;i--){
		sum*=a;
	}
	return sum;
}

int character_to_decimal(char character){ //,int base_from,int i){
	int d_number;
	if(character<='9' && character>='0') {
		d_number=character-'0';
	} else if(character>='a' && character<='z') {
		d_number=character-'a'+10;
	}
	return d_number;
}

int convert_to_dec(char* number,int base_from){
	int i, k;
	char decimal_array[65];
	int decimal_number;
	int length;
	for(i=0; number[i]!='\0'; i++){
		decimal_array[i]=character_to_decimal(number[i]); //,base_from,i*base_from^i);
		printf("%c -> %d\n",number[i],decimal_array[i]);
	}
	length=(strlen(decimal_array));
	printf("%d \n",length);
	for(k=0; decimal_array[k]!='\0'; k++){
		decimal_number+=decimal_array[k]*power(base_from,(length-(k+1)));
	}
	printf("The number in base 10 is: %d \n",decimal_number);
	return decimal_number;
}

void convert_to_new(int number, int base_to){
	int remainders[65], n, m, p, dividingstuff;
	char final_num[65];
	dividingstuff=number;
	for(n=64; dividingstuff!=0;n--){
		printf("dividingstuff before: %i ",dividingstuff);
		remainders[n]=dividingstuff%base_to;
		dividingstuff /= base_to;
		printf("dividingstuff after: %i, remainder: %i \n",dividingstuff,remainders[n]);
	};
	//for(p=64;remainders[p]!=0;p--){
	while(remainders[p]=='\0'){
		printf("%i, ", remainders[p]); // something's not right here
		p++;
	};
}

int main(int argc, char**argv){
	char number[65]; 
	int base_from, base_to, decimal_form;
	
	printf("what number would you have me convert? ");
	scanf("%s" , number);
	
	printf("what base was the number in? ");
	scanf("%i" , &base_from);
	
	printf("what base shall I convert it to? ");
	scanf("%i" , &base_to);
	
	printf("%s, %i, %i \n",number,base_from,base_to);
	
	decimal_form=convert_to_dec(number,base_from);
	convert_to_new(decimal_form,base_to);
	printf("the converted number is the backwards order of the remainders");
	return 0;
}