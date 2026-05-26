import tensorflow as tf
from keras.layers import Flatten, Dense, Input
from keras.datasets import mnist
from keras.models import Sequential
from keras.utils import to_categorical
import numpy as np
import streamlit as st
from streamlit_drawable_canvas import st_canvas
from PIL import Image, ImageOps
import os

st.set_page_config(page_title="MNIST Digit Calculator", layout="centered")
st.title("Calculate MNIST Digit")

MODEL_PATH = "mnist_model.h5"

@st.cache_resource
def train_mnist_model():
    if os.path.exists(MODEL_PATH):
        st.success("Loaded pre-trained model")
        return tf.keras.models.load_model(MODEL_PATH)
    
    (X_train, y_train), (X_test, y_test) = mnist.load_data()
    X_train = X_train/255.0
    X_test = X_test/255.0
    y_train = to_categorical(y_train, num_classes=10)
    y_test = to_categorical(y_test, num_classes=10)
    model = Sequential([
        Input(shape=(28,28)),
        Flatten(), 
        Dense(128, activation='relu'),
        Dense(10, activation='softmax')
    ])
    model.compile(
        optimizer='adam',
        loss='categorical_crossentropy',
        metrics=['accuracy']
    )
    model.fit(X_train, y_train, epochs=5, batch_size=32)
    test_loss, test_acc = model.evaluate(X_test, y_test)
    st.success(f"Test accuracy: {test_acc:.2f}")
    model.save(MODEL_PATH)
    return model

model = train_mnist_model()


canvas1, canvas2 = st.columns(2)
with canvas1:
    st.write("Draw a digit (0-9) below:")
    canvas_result1 = st_canvas(
        fill_color="#000000",
        stroke_width=15,
        stroke_color="#FFFFFF",
        background_color="#00000000",
        height=250,
        width=250,
        drawing_mode="freedraw",
        key='canvas1'
    )
    if canvas_result1.image_data is not None:
        img1=Image.fromarray((canvas_result1.image_data[:,:,0]).astype(np.uint8))
        img1=img1.resize((28,28)).convert("L")
        img_array1=np.array(img1).reshape(1,28,28)/255
        prediction1=model.predict(img_array1)
        pred_class1= np.argmax(prediction1)
        st.success(f"Predicted Digit Is {pred_class1}")

        if canvas_result1.image_data is not None:
            digit1, conf1 = pred_class1, np.max(prediction1)
            st.success(f"Digit 1 = {digit1}  |  Confidence = {conf1:.2f}")

with canvas2:
    st.write("Draw a digit (0-9) below:")
    canvas_result2 = st_canvas(
        fill_color="#000000",
        stroke_width=15,
        stroke_color="#FFFFFF",
        background_color="#00000000",
        height=250,
        width=250,
        drawing_mode="freedraw",
        key='canvas2'
    )
    if canvas_result2.image_data is not None:
        img2=Image.fromarray((canvas_result2.image_data[:,:,0]).astype(np.uint8))
        img2=img2.resize((28,28)).convert("L")
        img_array2=np.array(img2).reshape(1,28,28)/255
        prediction2=model.predict(img_array2)
        pred_class2= np.argmax(prediction2)
        st.success(f"Predicted Digit Is {pred_class2}")

        if canvas_result2.image_data is not None:
            digit2, conf2 = pred_class2, np.max(prediction2)
            st.success(f"Digit 2 = {digit2}  |  Confidence = {conf2:.2f}")





if (canvas_result1.image_data is not None) and (canvas_result2.image_data is not None):
    st.header("Selected Operation")
    operation = st.selectbox("Select Operation", ("Addition", "Subtraction", "Multiplication", "Division"))
    if st.button("Calculate"):
        if operation == "Addition":
            result = pred_class1 + pred_class2
            st.success(f"Result: {pred_class1} + {pred_class2} = {result}")
        elif operation == "Subtraction":
            result = pred_class1 - pred_class2
            st.success(f"Result: {pred_class1} - {pred_class2} = {result}")
        elif operation == "Multiplication":
            result = pred_class1 * pred_class2
            st.success(f"Result: {pred_class1} * {pred_class2} = {result}")
        elif operation == "Division":
            if pred_class2 != 0:
                result = pred_class1 / pred_class2
                st.success(f"Result: {pred_class1} / {pred_class2} = {result}")
            else:
                st.error("Error: Division by zero is not allowed.")