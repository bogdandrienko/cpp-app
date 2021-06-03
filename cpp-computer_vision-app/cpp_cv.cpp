#include <cpp_cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <map>
#include <iostream>
#include <QUrl>
#include <QObject>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QPixmap>
#include "filedownloader.h"
#include <stdio.h>
//#include <curl/curl.h>
//#include <CkHttp.h>

using namespace std;
using namespace cv;

void startAnalyse(map <string,string> SettingsMap)
{
//    for (auto it = SettingsMap.begin(); it != SettingsMap.end(); ++it)
//    {
//        cout << it->first << " : " << it->second << endl;
//    }
//    cout << SettingsMap["alias cam"] << endl;

//    QNetworkAccessManager *manager;
//    manager = new QNetworkAccessManager();
////    connect(manager, &QNetworkAccessManager::finished, this, &Downloader::onResult);
//    QUrl url("http://via.placeholder.com/300");
//    QNetworkRequest request;
//    request.setUrl(url);
//    manager->get(request);

//    QNetworkAccessManager nam;
//    QEventLoop loop;
//    QObject::connect(&nam,&QNetworkAccessManager::finished,&loop,&QEventLoop::quit);
//    QNetworkReply *reply = nam.get(QNetworkRequest(url));
//    loop.exec();
//    QPixmap pm;
//    pm.loadFromData(reply->readAll());

    QUrl url("http://103.3.229.181/digital-photo-frame-ads/public/getImages");//this link contains two images
                QNetworkAccessManager manager;
                QNetworkReply *response = manager.get(QNetworkRequest(QUrl(url)));
                QEventLoop event;
                connect(response,SIGNAL(finished()),&event,SLOT(quit()));
                event.exec();
                QString html = response->readAll();
                if(html.length() > 0){
                           QStringList str;
                           str = html.split(",");
                           for (int i = 0; i < str.size(); ++i)
                           {
                    pic=pic.remove(QRegExp(QString::fromUtf8("[`~!@#$%^&*()_â€”+=|;<>Â«Â»,?{}\'\"\\\[\\\]\\\\]")));
     QByteArray jpegData = pic.toLocal8Bit();
       QPixmap pixmap;
       pixmap.loadFromData(jpegData);
       QPixmap scaled = pixmap.scaled(128,64,Qt::IgnoreAspectRatio, Qt::FastTransformation);
       l.setPixmap(scaled);
       l.show();
       QString filename = QFileDialog::getSaveFileName(this, tr("Save Skin"), "/home/ihorse1/10-03-2015",tr("JPEG Image(*.jpg)"));
       QFile file (filename);
       file.open(QIODevice::WriteOnly);
       QDataStream out (&file);
       out << reply;
       qDebug()<<out;
       file.close();
    }
    }

//    cout << pm << endl;
//    namedWindow("My Image");
//    imshow("My Image", imdecode(pm, IMREAD_COLOR));

//    m_pImgCtrl = new FileDownloader(imageUrl, this);

//    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));

//    // read an image
//    Mat image = imread("C:\\Project\\Github_Projects\\cpp-app\\cpp-computer_vision-app\\1.jpg", 1);


//    _sources.append([f'{protocol}://192.168.{x}:{port}/ISAPI/Streaming/channels/101/'
//     f'picture?snapShotImageType=JPEG', cv2.imread(masks[index], 0),
//     sensitivity[index], correct[index], alias_device[index], alarm_level[index]])

//    h = httplib2.Http(os.path.abspath('__file__'))
//    h.add_credentials(login, password)
//    response, content = h.request(sources)
//    image = cv2.imdecode(numpy.frombuffer(content, numpy.uint8), cv2.IMREAD_COLOR)

//    bitwise_and = cv2.bitwise_and(image, image, mask=mask)
//    cvtcolor = cv2.cvtColor(bitwise_and, cv2.COLOR_BGR2HSV)
//    inrange = cv2.inRange(cvtcolor, numpy.array([0, 0, 255 - sensitivity_analysis], dtype=numpy.uint8),
//                          numpy.array([255, sensitivity_analysis, 255], dtype=numpy.uint8))
//    cv2.putText(inrange, f"{numpy.sum(inrange > 0) / numpy.sum(mask > 0) * 100 * correct_coefficient:0.2f}%",
//                (int(1920 / 5), int(1080 / 2)), cv2.FONT_HERSHEY_SIMPLEX, 3, (255, 255, 255), 3)
//    AnalyzeClass.render(name=f"final : {name}", source=inrange, resolution_debug=resolution_debug)
}
