string simplifyPath(string path) {
        
        stack<string> myStack;
        
        istringstream ss(path);
        string str;
        
        // push necessary directories in stack 
        while (getline(ss, str, '/')) 
            if (!str.empty()) {
                if (str == ".." && !myStack.empty())
                   myStack.pop();
                else if (str != "." && str != "..")
                   myStack.push(str);
            }
    
        // adding '/'
        string res;
        while (!myStack.empty()) {
              res = '/' + myStack.top() + res;
              myStack.pop();
        }
        
        
        return res.empty() ? "/" : res;
        
    }
