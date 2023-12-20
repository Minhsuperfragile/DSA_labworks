#include <stdio.h>
#include <string.h>

int isValid(char c){
	int isValid = 1;
	switch (c){
		case 0 ... 44:
			isValid = 0;
			break;
		case 47 :
			isValid = 0;
			break;
		case 58 ... 63:
			isValid = 0;
			break;
		case 91 ... 94:
			isValid = 0;
			break;	
		case 96:
			isValid = 0;
			break;
		case 123 ... 127: // use 255 if \J option is used
			isValid = 0;
			break;
		default:
			isValid = 1;
			return isValid;
	}
	return isValid;
}

void emailDetection(char input[]){
	int size = strlen(input);
	int startCharHolder, endCharHolder, at=0;
	for (int i=0;i<size;i++){
		if (!isValid(input[i])){
			if (!at){
				startCharHolder = i+1;
				while (input[startCharHolder] == 45 || input[startCharHolder] == 46){ // 45 = - and 46 = .
					startCharHolder++;
				}
			}
			else{
				endCharHolder = i-1;
				while (input[endCharHolder] == 45 || input[endCharHolder] == 46){ // 45 = - and 46 = .
					endCharHolder--;
				}
				at = 0;
				for (int j=startCharHolder;j<=endCharHolder;j++){
					printf("%c",input[j]);
				}
				printf("\n");	
			}
		}
		if (input[i] == 64 && startCharHolder != i){ // 64 = @
			at = 1;
		}
	}
}

int main(){
	char in[] = "Valid emails are ow91_oo@kd.pp, co2@o3_23.tt and uiw-it@st.sa.l9. Invalid examples are yy$73@fs.cc, @fs.cc, --g-s@sadf.tt, o23@.";
	emailDetection(in);
	return 0;
}