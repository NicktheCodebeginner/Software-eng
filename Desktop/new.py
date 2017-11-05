import json
import sys
import jieba
import time

def change(fileName):
    fileContent = open(fileName)
    trainSet = json.load(fileContent)
    length = len(trainSet)
    newTrainSet = []
    startTime = time.time()
    for i in range(length):
        tempDic = {}
        filePath = '/caption_train_images_20170902/' + trainSet[i]['image_id']
        captions = []
        for j in range(5):
            cutSentence = jieba.lcut(trainSet[i]['caption'][j], cut_all = False)
            captions += cutSentence
        tempDic['file_path'] = filePath
        tempDic['captions'] = captions
        newTrainSet.append(tempDic)
        print('%dth captions has done' % i)
    doneTime = time.time()
    newFile = open('newCaptions.json', 'w')
    newFile.write(json.dumps(newTrainSet))
    print("Time consume: %ds" % int(doneTime - startTime))

if __name__ == '__main__':
    f_input = sys.argv[1]
    change(f_input)