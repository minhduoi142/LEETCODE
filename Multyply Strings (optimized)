class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int len1=num1.length(), len2=num2.length(), sum=0;
        int* arr = new int[len1 + len2]();

        for(int i=len1-1; i>=0; i--){
            for(int j=len2-1; j>=0; j--){
                sum= ((num1[i]-'0')*(num2[j]-'0')) + arr[i+j+1];
                arr[i+j+1] = sum%10;
                arr[i+j] += sum/10;
            }
        }

        string result="";
        bool lz=true;
        for(int k=0; k<len1+len2; k++){
            if(arr[k]==0 && lz) continue;
            lz=false;
            result+= arr[k]+'0';
        }
        return result;
    }
};
