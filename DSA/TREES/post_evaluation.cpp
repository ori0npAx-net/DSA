include <iostream>
using namespace std;

int evaluate(string postfix){
    stack<int>st;

    for (int i=0;i<postfix.length;i++){
        char cur= postfix[i];
        if (cur==" ")continue;

        if (cur>='0'&&cur<='9'){
            int num=cur-'0';
            st.push(num);
        }
        else{
            int val1=st.top();
            st.pop();
            int val2=st,top();
            st.pop();

            int ans=applyOperator(val1,val2,cur);
            st.push(ans);
        }
    }
    return st.top();
}

  //hardcoded
int main(){
    string postfix[]= {'2','3','2','*','4','/','+'};
    int result =evaluate(postfix);
    cout<<"result= "<<result;
    return 0;
}


