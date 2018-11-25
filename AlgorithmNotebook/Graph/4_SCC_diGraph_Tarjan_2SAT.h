
// O( V + E)
// Input format: L = (x2 v -x1) (-x1 v x2) (x1 v x3) (-x2 v -x3) (x1 v x4)
//                      numVar = 4
// 2 -1
// -1 -2
// 1 3
// -2 -3
// 1 4

// Algo:
//      Find x1,x2,x3,x4 satisfy the L (L true)
//      Ex: L = (x2 v -x1) (-x1 v x2) (x1 v x3) (-x2 v -x3) (x1 v x4)
//          -create graph with (a v b) = 
//              (-a)----->(b)
//              (-b)----->(a)
//          - my rule:
//                     a = i * 2 - 1
//                    -a = i * 2
//          - Ex: 
//              a1: a1 = (1)   and -a1  = (2)
//              a2: a2 = (3)   and -a2 = (4)
//
//          - Final result(res = [1]0 [2]0 [3]1 [4]1)
//                  x1 = false, x2 =false, x3 = true, x4 = true 


/* -------------- 2SAT ----------------- */
class TwoSAT {
private:
    int numVar;
    vector<pair<int,int>> sat;
    Tarjan tarjan;
    vector<bool> results;


    inline pair<int,int> getVertexID(int i) {
        if(i > 0)
            return {i*2 - 1, i*2};
        return {-i*2, -i*2 -1};
    }
    inline pair<int,int> getVar(int i) {
        return {i*2-1, i*2};
    }
    void createGraph() {
        for(int i = 0; i < this->sat.size(); ++i) {
            int a = this->sat[i].first;
            int b = this->sat[i].second;

            pair<int,int> var_a = this->getVertexID(a);
            int va = var_a.first;
            int va_ = var_a.second;

            pair<int,int> var_b = this->getVertexID(b);
            int vb = var_b.first;
            int vb_ = var_b.second;

            this->tarjan.addEdge(va_, vb);
            this->tarjan.addEdge(vb_, va);
        }
    }
public:
    TwoSAT(int num): numVar(num), tarjan(num*2) {
        this->results.assign(num+1, false);
    }
    void getInput(int a, int b) {
        this->sat.push_back( {a,b} );
    }
    bool solve_TwoSat() {
        // Get SCC
        this->createGraph();
        this->tarjan.find_SCC();
        vector<vector<int>> SCC = this->tarjan.get_SCC();

        // Assgin Group id
        int groupID = 1;
        vector<int> SCC_id(this->numVar*2+1);
        for(int i=0; i<SCC.size(); ++i) {
            for(int j=0; j<SCC[i].size(); ++j) {
                SCC_id[SCC[i][j]] = groupID;
            }
            ++groupID;
        }

        //check SCC and yield results
        for(int i = 1; i <= this->numVar; ++i) {
            pair<int,int> var = getVar(i);
            int posVar = var.first;
            int negVar = var.second;

            if(SCC_id[posVar] == SCC_id[negVar])
                return false;

            if(SCC_id[posVar] < SCC_id[negVar])
                this->results[i] = true;
            else
                this->results[i] = false;
        }
        return true;
    }
    vector<bool> get_Results() {
        return this->results;
    }
};
