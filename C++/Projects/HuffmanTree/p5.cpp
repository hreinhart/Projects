#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class huffNode{
   public:
      char data;
      int freq;
      class huffNode *left, *right;
};

class tree{
   public:
      int size, capacity;
      huffNode **array;
};
huffNode* node(char let, int freq){
   huffNode* tmp = (huffNode*)malloc(sizeof(huffNode));
   tmp->left = tmp->right = NULL;
   tmp->data = let;
   tmp->freq = freq;
   return tmp;
}
tree* create(int uniq2){
   tree* themeat = (tree*)malloc(sizeof(tree));
         themeat->size = 0;
         themeat->capacity = uniq2;
         themeat->array = (huffNode**)malloc(themeat->capacity*sizeof(huffNode*));
         return themeat;
}
int isLeaf(struct huffNode* root){
return !(root->left) && !(root->right);
}
void swap(huffNode** fucked, huffNode** up){
   huffNode* tmp = *fucked;
   *fucked = *up;
   *up = tmp;
}
void fix(tree* thing, int i){
   int sml = i;
   int lft = 2 * i + 1;
   int rght = 2 * i +2;

   if(lft < thing->size && thing->array[lft]->freq < thing->array[sml]->freq){
      sml = lft;
   }
   if(rght < thing->size && thing->array[rght]->freq < thing->array[sml]->freq){
      sml = rght;
   }
   if(sml != i){
      swap(&thing->array[sml],&thing->array[i]);
      fix(thing,sml);
   }
}
void build(tree* thing){
   int yah = thing->size-1;
   for(int i = (yah-1) /2; i >=0; i--){
      fix(thing, i);
   }
}
tree* buildminheap(char lets[], int freq[], int uniq2){
   tree* thething = create(uniq2);

   for(int i = 0; i < uniq2;i++){
      thething->array[i] = node(lets[i],freq[i]);
   }
   thething->size = uniq2;
   build(thething);

   return thething;
}
huffNode* takemin(tree* tree){
   huffNode* tmp = tree->array[0];
   tree->array[0] = tree->array[tree->size-1];
   tree->size--;
   fix(tree, 0);
   return tmp;
}
void insert(tree* tree, huffNode* node){
   tree->size++;
   int i = tree->size-1;
      while(i && node->freq < tree->array[(i-1)/2]->freq){
         tree->array[i] = tree->array[(i-1)/2];
         i = (i-1)/2;
      }
      tree->array[i] = node;
      
}
huffNode* mergesHuff(char lets[], int freq[], int uniq2){
      huffNode *left, *right, *parent;

      tree* tree = buildminheap(lets, freq, uniq2);

      while(tree->size != 1){
         left = takemin(tree);
         right = takemin(tree);

         parent = node('~', left->freq + right->freq);
         parent->left = left;
         parent->right = right;

         insert(tree, parent);
      }

      return takemin(tree);
}

void getcodes(huffNode* root, string huff[], int start,int ffreq[], int fhuff[], char flets[]){
   if(root->left){
      huff[start] = "0";
      getcodes(root->left,huff,start+1, ffreq, fhuff, flets);
   }
   if(root->right){
      huff[start] = "1";
      getcodes(root->right,huff,start+1, ffreq, fhuff, flets);
   }
   if(isLeaf(root)){
      flets[root->data] = root->data;
      ffreq[root->data] = root->freq;
      fhuff[root->data] = start;
   }
}
void buildHuff(char lets[], int freq[], int uniq2, string huff[],int ffreq[], int fhuff[], char flets[]){

      huffNode* root = mergesHuff(lets,freq,uniq2);
      int start = 0;

      getcodes(root, huff, start, ffreq, fhuff, flets);

}
int main(int argc, char *argv[]) {
   ifstream f;
   f.open(argv[1]);
   char letters[256];
   int freq[256] = {0};
   int count = 0;
   int uniq = 0;
   int uniq2 = 0;
   char finallets[256];
   int finalfreq[256] = {0};
   int finalhuff[256] = {0};
   string huff[256] = {""};
   char temp;
   char input[100001];
   int finalcount = 0;
   while(f.get(temp)){
      input[count] = temp;
      count++;
   }
   for(int i = 0; i < count; i++){
      uniq = 0;
      for(int j = 0; j < 256; j++){
         if (input[i] == letters[j]){
            uniq++;}
         }
      if(uniq == 0){
         letters[uniq2] = input[i];
         for(int k = 0; k < count; k++){
            if(letters[uniq2] == input[k]){
               freq[uniq2]++;
            }
         }
         uniq2++;
      }
   }
      buildHuff(letters,freq,uniq2,huff,finalfreq,finalhuff,finallets);
      for(int i = 0; i < count+1; i++){
         finalcount += finalhuff[input[i]];
      }
   cout << "Uncompressed length: " << count * 8 << " bits" <<endl;
   cout << "Compressed length: " << finalcount << " bits" << endl;
   cout << "CHAR|FREQ|CODE_LEN" << endl;
   for(int i = 0; i < 256; i++){
      if(finalfreq[i] > 0 && finalhuff[i] > 0){
      cout << "'" << finallets[i] << "'" << "|" << finalfreq[i] << "|" << finalhuff[i] << endl;}
   }
   return 0;
}
