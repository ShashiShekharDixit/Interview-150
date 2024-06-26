class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::string> sol;
        std::string plc;
        for (size_t i=0;i<words.size();i++){
            if (i!=0 && plc.length()+words[i].length()+1>static_cast<size_t>(maxWidth)){
                auto it=std::find(plc.begin(), plc.end(),' ');
                if (it==plc.end()){
                    while(plc.length()<static_cast<size_t>(maxWidth)){
                        it=plc.insert(it,' ');
                    }
                } else{
                    while(plc.length()<static_cast<size_t>(maxWidth)){
                        it=plc.insert(it,' '); 
                        it=std::find_if(it,plc.end(),[](char c){return c!=' ';});
                        it=std::find(it,plc.end(),' ');
                        if(it==plc.end()){ 
                            it=std::find(plc.begin(),plc.end(),' ');       
                        }
                    }
                }                
                sol.push_back(plc);
                plc.clear();
                plc.append(words[i]); 
            } else {
                if (plc.size()==0){ 
                    plc.append(words[i]);
                } else { 
                    plc.append(1,' ');
                    plc.append(words[i]);
                }
            }
        }
        auto it=plc.end();
        while(plc.length()<static_cast<size_t>(maxWidth)){
            it=plc.insert(it,' ');
        }
        sol.push_back(plc);
        return sol;
    }
};