import random

TEST_SET = list(set(random.sample(range(1, 25), 5)))
TRAIN_SET = [i for i in range(1, 26) if i not in TEST_SET]  # not in TEST_SET]


def line2words(s):
    import re
    return [i.lower() for i in re.findall('[a-zA-Z0-9]+', s) if len(i) >= 2]


def load(path):
    with open(path, encoding='utf-8') as f:
        data = f.readlines()
    result = []
    for line in data:
        result += line2words(line)
    return result


def make_dict(set):
    from os.path import join
    dict = {}
    for i in set:
        for j in load(join(r'./email/ham', '{0}.txt'.format(i))):
            if j in dict:
                dict[j] += 1
            else:
                dict[j] = 1
    ham_dict = dict.copy()
    spam_dict = {}
    for i in set:
        for j in load(join(r'./email/spam', '{0}.txt'.format(i))):
            if j in dict:
                dict[j] += 1
            else:
                dict[j] = 1
            if j in spam_dict:
                spam_dict[j] += 1
            else:
                spam_dict[j] = 1
    return dict, ham_dict, spam_dict


if __name__ == '__main__':
    a, b, c = make_dict()
