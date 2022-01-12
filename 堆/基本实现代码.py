class Heap():
    def __init__(self,ls) -> None:
        self.ls=ls
        self.heapSize=len(ls)
    #使用迭代的方式进行 最大堆-->最小堆同理 
    def maxHeap01(self,start, end):
        dad=start
        son=dad*2+1
        while son<=end:
            if son+1 <=end and self.ls[son]<self.ls[son+1]:son+=1
            if self.ls[dad]>self.ls[son]:return
            else:
                self.ls[dad],self.ls[son]=self.ls[son],self.ls[dad]
                dad=son
                son=dad*2+1#dad的数值是比较小的
    def minHeap01(self,start, end):
        dad=start
        son=dad*2+1
        while son<=end:
            if son+1<=end and self.ls[son]>self.ls[son+1]:son+=1
            if self.ls[son]>self.ls[dad]:return
            else:
                self.ls[dad],self.ls[son]=self.ls[son],self.ls[dad]
                dad=son
                son=dad*2+1
    def buildHeap01(self):
        #从最后一个父节点进行逆序遍历
        for x in range(self.heapSize>>1,-1,-1):
            self.maxHeap01(x,self.heapSize-1)
    def buildHeap03(self):
        #从最后一个父节点进行逆序遍历
        for x in range(self.heapSize>>1,-1,-1):
            self.minHeap01(x,self.heapSize-1)
    #使用递归的方式进行
    def maxHeap02(self,i):
        left,right,largest=i*2+1,i*2+2,i
        if left<self.heapSize and self.ls[largest]<self.ls[left]:largest=left
        if right<self.heapSize and self.ls[largest]<self.ls[right]:largest=right

        if largest!=i:
            self.ls[i],self.ls[largest]=self.ls[largest],self.ls[i]
            self.maxHeap02(largest)
    def buildHeap02(self):
        #从最后一个父节点进行逆序遍历
        for x in range(self.heapSize>>1,-1,-1):
            self.maxHeap02(x)
if __name__=='__main__':
    ls=[3,2,3,1,2,4,5,5,6]
    s=Heap(ls)
    s.buildHeap03()
    print(ls)