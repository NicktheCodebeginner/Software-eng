import json
import sys

def change(fileName):
    fileContent = open(fileName)
    trainSet = json.load(fileContent)
    length = len(trainSet)
    new_train = []
    for i in range(length):
        tempDic = {}
        tempDic['file_path'] = '/caption_train_images_20170902/' + trainSet[i]['image_id']
        tempDic['captions'] = trainSet[i]['caption']
        new_train.append(tempDic)
    newFile = open('newCaptions.json', 'w')
    newFile.write(json.dumps(new_train))

if __name__ == '__main__':
    f_input = sys.argv[1]
    change(f_input)