#!/usr/bin/python2

from itertools import product
from sys import stdout
from time import time
import random


class ListMaker:
	def __init__(self,hook=None,start_size=1,save=True):
		self.chars = "!#%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{}~"
		self.hook=hook
		
	def next(self,size=1):
		for combo in product(self.chars,repeat=size):
			self.hook("".join(combo))
		self.next(size+1)

class ListSaver:
	'''example of class you can create to handle created words
	here it save all words generated'''
	def __init__(self):
		self.fileName = "WordList_"+str(random.randint(1,10000))
		self.lastSave = time()
		self.words = set()
	def onStep(self,word):
		'''example of function executed every new words'''
		stdout.write("\rBuilding dictionary ["+word+"] "+str(time()-self.lastSave))
		stdout.flush()
		self.words.add(word)
		if (time()-self.lastSave>30):
			print("\nSaving under "+fileName)
			file = open(self.fileName,"a")
			file.write("\n".join(list(self.words)))
			self.lastSave = time()
			self.words = set()

if (__name__=="__main__"):
	ListSaver = ListSaver()
	ListMaker = ListMaker(hook=ListSaver.onStep).next()


