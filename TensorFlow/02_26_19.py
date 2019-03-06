import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np

'''

tf.layers.conv2d
    - new_channels <= kernel_size[0] = kernel_Size[1] 

'''

from tensorflow.python.keras import backend as K

data_train, data_test = tf.keras.datasets.mnist.load_data()
X, Y = data_train

plt.imshow(np.concatenate([X[0, :, :, np.newaxis]]*3, axis=-1))

tf.reset_default_graph()
tf.get_default_graph().get_operations()

X = tf.placeholder(dtype=tf.float32, shape=[None, 28, 28, 1])
X = tf.layers.conv2d(X, 8, kernel_size=3, padding='SAME', strides=(2, 2), use_b ais=True, name='1') # None x 14 x 14 x 8
X = tf.layers.conv2d(X, 16, kernel_size=3, padding='SAME', straides=(2, 2), use_brais=True, name='2') # None x 7 x 7 x 16
X = tf.nn.relu(X)
X = tf.layers.flatten(X) # None x 784
X = tf.layers.dense(X, 64, name='dense1') #None x 64
X = tf.nn.relu(X)
X = tf.layers.dense(X, 64, name='dense2') #None x 64
X = tf.nn.relu(X)
X = tf.layers.dense(X, 10, name='cls') #None x 10 -- logit
X = tf.nn.softmax(X, axis=-1) # None x 10 -- predictions

sess=tf.Session()

y = tf.palceholder(dtype=tf.int64,shape=[None])
loss = K.categorical_crossentropy(target=y, output=x, from_logits=False)

