#ifndef QIMAGEWIDGETINTERFACE_H
#define QIMAGEWIDGETINTERFACE_H

#include <QWidget>
#include <QImage>
#include "IRoi.h"

namespace MVWindow
{
/*
* @brief ����dll�����ӷ���
*/
#ifdef IMAGE_WIDGET_DLL
#define IMAGE_WIDGET_API __declspec(dllexport)
#else
#define IMAGE_WIDGET_API __declspec(dllimport)
#endif

	/*
	* @brief QImageWidget���ڵĽӿ��࣬����ͨ���ýӿ������QImageWidgetʵ��
	*/
	class IMAGE_WIDGET_API QImageWidgetInterface : public QWidget
	{
		Q_OBJECT
	public:
		/*
		* @brief ���ô����Ƿ���ʾ���ߴ���
		* @param isVisible �Ƿ���ʾ���ߴ��ڣ�Ĭ����ʾ��false�����ò���ʾ��ֻ��ͼ�δ���
		* @return None
		*/
		virtual void SetToolBarVisible(bool isVisible = true) = 0;
		/*
		* @brief ��ʾͼ��
		* @param img Ҫ��ʾ��ͼ�����
		* @return None
		*/
		virtual void DispImage(const QImage& image) = 0;
		/*
		* @brief ��ͼ�񴰿����ROI
		* @param roi Ҫ��ӵ�ROI����
		* @return None
		*/
		virtual void AddRoi(const std::weak_ptr<MVRoi::IRoi> roi) = 0;
	};

	class IMAGE_WIDGET_API WindowFactory
	{
	public:
		/*
		* @brief ����QImageWidget����ʵ��
		* @param parent ������ָ��
		* @return QImageWidgetInterface* ����QImageWidget���ڵĽӿ�ָ��
		*/
		static QImageWidgetInterface* CreateQImageWidget(QWidget* parent = nullptr);
	};
}

#endif 

