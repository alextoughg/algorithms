vector<string> tokenizer(string f, string delim){
    vector<string> result;
    int p,t;
    if ((p = f.find(delim))== string::npos){
        result.push_back(f);
    }
    else{
        result.push_back(f.substr(0,p));
        t = p;
        while((p = f.find(delim, t+1)) != string::npos){
            result.push_back(f.substr(t+1, p-(t+1)));
            t = p;
        }
        result.push_back(f.substr(t+1, p-(t+1)));
    }
    return result;
}

// x^y, efficiently. How can I make this iterative?
int toThe(int x, int y){
    if(y == 0) return 1;
    else{
        if(y % 2 == 0){
            int t = toThe(x,y/2);
            return t*t;
        }
        else{
            int t = toThe(x, y-1);
            return x*t;
        }
    }
}
