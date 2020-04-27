from data_util import read_data, score

number = 400
label = []
for i in range(7):
    label.extend([i] * number)

train_data = read_data('train', number)
eval_data = read_data('evaluate', number)

print('svm is ', score('svm', train_data, label, eval_data, label))
print('decision tree is ', score('decision_tree', train_data, label, eval_data, label))
print('k neighbour is', score('k_neighbour', train_data, label, eval_data, label))
print('random forest is', score('random_forest', train_data, label, eval_data, label))
