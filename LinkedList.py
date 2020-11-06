class Node:
    def __init__(self,data=None,next=None):
        self.data=data
        self.next=next
        
        
class LinkedList:
    def __init__(self):
        self.head=None
        
    def insert_at_big(self,data):
        node=Node(data,self.head)
        self.head=node
        
    def print(self):
        if self.head is None:
            print("Empty")
            return
        itr=self.head
        itst=''
        while itr:
            itst+= str(itr.data)+" --> " if itr.next else str(itr.data)
            itr = itr.next
            
        print(itst)
        
    def get_len(self):
        count = 0
        itr = self.head
        while itr:
            count+=1
            itr=itr.next
            
    
    def insert_after_value(self, data_after, data_to_insert):
        itr =self.head
        if self.head == data_after:
            
    # Search for first occurance of data_after value 
    # Now insert data_to_insert after data_after node
        
        

    def remove_by_value(self, data):
    # Remove first node that contains data