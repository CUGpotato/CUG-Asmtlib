import cv2
import os
from os.path import join
import random

from sklearn import svm, tree, neighbors, ensemble
from seaborn import heatmap
from matplotlib import pyplot as plt

train_path = r'./data/Train'
labels = [i for i in os.listdir(train_path)]

clfs = {
    'svm': svm.SVC(),
    'decision_tree': tree.DecisionTreeClassifier(),
    'k_neighbour': neighbors.KNeighborsClassifier(),
    'random_forest': ensemble.RandomForestClassifier()
}


def handle_data():
    for i in range(len(labels)):
        index = 0
        for path, subdir, files in os.walk(os.path.join(r'./data/Train', labels[i])):
            for name in files:
                if name.endswith('.png'):
                    try:
                        img = cv2.imread(os.path.join(path, name))
                        img = cv2.resize(cv2.cvtColor(img, cv2.COLOR_BGR2GRAY), (64, 64))
                        cv2.imwrite(os.path.join("./data/train", labels[i], '{}.png'.format(str(index).zfill(4))),
                                    img)
                        index += 1
                    except Exception as e:
                        print(index, e)


def read_data(_type, number=100):
    _data = []
    for label in labels:
        tmp = list(range(
            len([i for i in os.listdir(join(r'data', _type, label))])
        ))
        random.shuffle(tmp)
        for file_name in tmp[:number]:
            _data.append(
                cv2.imread(join(r'data', _type, label, '{}.png'.format(str(file_name).zfill(4))),
                           cv2.IMREAD_GRAYSCALE).flatten().tolist()
            )
    return _data


def score(method, train_data, train_label, eval_data, eval_label):
    clf = clfs[method].fit(train_data, train_label)
    predict = clf.predict(eval_data)
    w = h = len(labels)
    confusion_matrix = [[0 for i in range(w)] for j in range(h)]
    cnt = 0
    for i in range(len(predict)):
        if eval_label[i] == predict[i]:
            cnt += 1
        confusion_matrix[eval_label[i]][predict[i]] += 1

    hm = heatmap(data=confusion_matrix, vmin=0, vmax=125,
                 cmap="Oranges", square=True, linewidths=6.,
                 xticklabels=labels, yticklabels=labels, cbar=False, annot=True, fmt='g')
    hm.xaxis.tick_top()
    hm.xaxis.set_label_position('top')
    plt.yticks(rotation=0)

    plt.show()
    hm.get_figure().savefig(method)

    return cnt / len(eval_label)


if __name__ == '__main__':
    hm = heatmap([[1, 2], [3, 4]], xticklabels=[1, 2], yticklabels=[1, 2])
    hm.xaxis.tick_top()
    hm.xaxis.set_label_position('top')
    plt.yticks(rotation=0)
    plt.show()
    hm.get_figure().savefig('ddd')
