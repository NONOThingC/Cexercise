def deploy(img_path):
    caffe.set_mode_gpu()
    net = caffe.Classifier(ARCHITECTURE, WEIGHTS,
                           channel_swap=(2,1,0),
                           raw_scale=255,
                           image_dims=(256, 256))
    input_image= caffe.io.load_image(img_path)
    input_image = cv2.resize(input_image, (256,256))
    mean_image = caffe.io.load_image('/dli/data/digits/20181026-004906-337a/mean.jpg')
    input_image = input_image-mean_image
    prediction = net.predict([input_image])
    if prediction.argmax()==0:
        return "whale"
    else:
        return "not whale"
if __name__ == '__main__':
    print(deploy(sys.argv[1]))
