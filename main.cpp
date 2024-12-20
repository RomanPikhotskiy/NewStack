#include "ExpressionChecker.h"

int main(){
    Table<int, int> t( "t1", "t2", 10);
    t.Print();
    ExpressionChecker str;
    cout << (str.CheckBrackets("(") ? "true" : "false");
    return 0;
}