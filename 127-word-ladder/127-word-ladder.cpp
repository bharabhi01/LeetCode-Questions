class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words;
        
        // To check if the end word is present in our wordList.
        bool isPresent = false;
        
        // Insert all the words from the wordList to our set.
        for(auto word: wordList)
        {
            if(endWord.compare(word) == 0)
                isPresent = true;
            
            words.insert(word);
        }
        
        // If endWord is not present in our wordList, we will return 0 as we can't find the shortest path.
        if(isPresent == false)
            return 0;
        
        queue<string>wordQueue;
        wordQueue.push(beginWord);
        
        // This will measure the level of BFS.
        int path = 0;
        
        // BFS begins.
        while(!wordQueue.empty())
        {
            path += 1;
            
            // No of elements at a level.
            int elementsSize = wordQueue.size();
            
            while(elementsSize--)
            {
                string curr = wordQueue.front();
                wordQueue.pop();
                int len = curr.length();
                
                
                // Trying every possible combinations on every single word.
                for(int i = 0; i < len; i++)
                {
                    string temp = curr;
                    
                    // Trying every possible letter at every index.
                    for(char letter = 'a'; letter <= 'z'; letter++)
                    {
                        temp[i] = letter;
                        
                        // We don't want to use the same letter.
                        if(curr.compare(temp) == 0)
                            continue;
                        
                        // If the word we formed by combining is the same as the endWord,
                        // then, we would return the path + 1, it would be our ans.
                        if(temp.compare(endWord) == 0)
                            return path + 1;
                        
                        // We will push the curr word into the queue and erase it from our set.
                        if(words.find(temp) != words.end())
                        {
                            wordQueue.push(temp);
                            words.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};