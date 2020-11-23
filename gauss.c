#include <stdio.h>

double get_x1( double x2, double x3){

	return( (10.0 - x2 - x3) / 5.0 );
}

double get_x2( double x1, double x3){

	return( (12.0 - x1 - x3) / 4.0);
}

double get_x3( double x1, double x2){

	return( (13.0 - 2.0 * x1 - x2) / 3.0);
}

int main(){
    
	double X1, X2, X3;  //計算前の値
	double x1, x2, x3;  //計算後の値
	int i;
	double e = 0.000001;    //許容誤差
	
	x1 = x2 = x3 = 1.0;     //初期値

	for(i=0; i<20; i++){
	    X1 = x1;
	    X2 = x2;
	    X3 = x3;
	    
	    x1 = get_x1( x2, x3);
	    x2 = get_x2( x1, x3);
	    x3 = get_x3( x1, x2);

	    printf("[i=%d] x1 = %.10f, x2 = %.10f, x3 = %.10f\n", i+1, x1, x2, x3);
	    
	    if(x1-X1<e && x2-X2<e && x3-X3<e)   //収束条件
	        break;
	}

	return 0;
}
