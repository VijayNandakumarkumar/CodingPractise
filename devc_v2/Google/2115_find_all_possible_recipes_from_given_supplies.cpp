/*

2115. Find All Possible Recipes from Given Supplies

You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

 

Example 1:

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".

Example 2:

Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".

Example 3:

Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".

*/

class Solution {
public:
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> mps;
        unordered_map<string, int> smap;
        vector<string> res;
        unordered_set<string> visited;
        
        int rlen = recipes.size();
        int slen = supplies.size();
        for (int i=0; i<slen; i++) {
            smap[supplies[i]]++;
        }
        for (int i=0; i<rlen; i++) {
            string rp = recipes[i];
            vector<string> igs = ingredients[i];
            auto it = visited.find(rp);
            if (it == visited.end() 
                && canMakeRecipe(rp, recipes, igs, smap, ingredients, visited, res, mps)) {
                mps[rp] = 1;
                res.push_back(rp);
                // cout<<"Push recipe "<<rp<<endl;
            }
        }
        return res;
    }
    
    //should return true if the recipe can be made.
    bool canMakeRecipe(string rp, vector<string> &rps, 
                       vector<string> &igs, unordered_map<string, int> &sps, 
                       vector<vector<string>>& ingredients, unordered_set<string> &visited, 
                       vector<string> &res, unordered_map<string, int> &mps) {
        // cout<<"The visiting recipe is : "<<rp<<endl;
        visited.insert(rp);
        int iglen = igs.size();
        for(int i=0; i<iglen; i++) {
            string ig = igs[i];
            // cout<<"IG - "<<ig<<endl;
            if (visited.find(ig) == visited.end()) {
                // cout<<"IG - Visiting for first time"<<endl;
                visited.insert(ig);
                if (sps[ig] >= 1) {
                    // cout<<"IG - Found in supplied"<<endl;
                    mps[ig] = 1;
                } else if (find(rps.begin(), rps.end(), ig) != rps.end()) {
                    // cout<<"IG - Found in recipes"<<endl;
                    int pos = find(rps.begin(), rps.end(), ig) - rps.begin();
                    if (canMakeRecipe(ig, rps, 
                                      ingredients[pos], sps, 
                                      ingredients, visited, res, mps)) {
                        // cout<<"IG - RP - Can be made"<<endl;
                        mps[ig] = 1;
                        // cout<<"Push recipe "<<ig<<endl;
                        res.push_back(ig);
                    } else {
                        // cout<<"IG - RP can be made"<<endl;
                        mps[ig] = 0;
                        return false;
                    }
                } else {
                    mps[ig] = 0;
                    return false;
                }
            } else if (mps[ig] != 1) {
                // cout<<"IG - Already visited and can't be made"<<endl;
                return false;
            }
        }
        // cout<<"Returning true for rp : "<<rp<<endl;
        return true;
    }
};