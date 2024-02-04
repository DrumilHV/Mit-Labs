import java.util.*;
import java.lang.String ;
class commaAdder{
    String number;String commaSeperatedNumber = ;
    String addComma(String number){
        int j=0;
        for(int i = number.length();i<=0; i--){
            commaSeperatedNumber.charAt(j) = number.charAt(i).;
            if(i%3==0){
                commaSeperatedNumber.charAt(j++) = ',';
            }
        }
        return number;
        
    }
}