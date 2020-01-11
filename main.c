#include "Trie.h"
int maxSize=0;
int main() {



	node* root = getNewTrieNode(' '); // initializing the root
	char c=0; 
	char* str= NULL;
	Node* head = NULL;
	int count = 0;

	while (((c = getc(stdin)) != EOF)) {
		
		if (c != ' ' && c!='\n' && c!='.' && c!=',') {
			count++;
			if(c<97 || c>122){ // if c is not small letter
				c=c+'a'-'A';
			}
			head = add(head, c);
		}
		
		if (c == ' ' || c=='\n') {
			if(maxSize<count){
			maxSize=count; // saving the maximum length of word 						//that we get
			}
			str = fromListToStr(head,str,count);
					
					insert(root, str);
					 head =freeList(head);
					free(str);
					str=NULL;
					count = 0;




		}

		


	}
	
					
	free(str);
	printTreeLexUp(root);
	printf("------\n");
	//printTreeLexDown(root);
	freeTree(root);
	free(root);
	root=NULL;



	return 0;
}
