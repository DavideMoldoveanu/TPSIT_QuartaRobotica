class Node:
    def __init__(self,data):  #__init__ prende solo il data, il self solo nella definizione
        self.left = None
        self.right = None
        self.data = data 

    def insert(self,data):
    # conftonta il nodo da aggiungere con il nodo da aggiungere
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
             self.data = data
   

    def inOrderTraversal(self,root):
        res = []
        if root:
            res = self.inOrderTraversal(root.left)
            res.append(root.data)
            res = res + self.inOrderTraversal(root.right)
        return res


    def postOrder(self,root):
        res = []
        if root:
            res = self.postOrder(root.left)
            res = res + self.postOrder(root.right)
            res.append(root.data)
        return res
    

    #metodo che mette in una lista solo i nodi pari
    def Pari(self,root):
        lista = self.inOrderTraversal(root)
        listaP = []
        for k in lista:
            if k % 2 == 0:
                listaP.append(k)
        return listaP 
        
#inserimento
root = Node(26)
root.insert(14)
root.insert(35)
root.insert(10)
root.insert(19)
root.insert(31)
root.insert(42)

print(root.postOrder(root))
print(root.Pari(root))