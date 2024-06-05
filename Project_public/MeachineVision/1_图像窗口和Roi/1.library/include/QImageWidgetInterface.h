#ifndef QIMAGEWIDGETINTERFACE_H
#define QIMAGEWIDGETINTERFACE_H

#include <QWidget>
#include <QImage>
#include "IRoi.h"

namespace MVWindow
{
/*
* @brief 定义dll的链接符号
*/
#ifdef IMAGE_WIDGET_DLL
#define IMAGE_WIDGET_API __declspec(dllexport)
#else
#define IMAGE_WIDGET_API __declspec(dllimport)
#endif

	/*
	* @brief QImageWidget窗口的接口类，可以通过该接口类操作QImageWidget实例
	*/
	class IMAGE_WIDGET_API QImageWidgetInterface : public QWidget
	{
		Q_OBJECT
	public:
		/*
		* @brief 设置窗口是否显示工具窗口
		* @param isVisible 是否显示工具窗口；默认显示，false则设置不显示，只有图形窗口
		* @return None
		*/
		virtual void SetToolBarVisible(bool isVisible = true) = 0;
		/*
		* @brief 显示图像
		* @param img 要显示的图像对象
		* @return None
		*/
		virtual void DispImage(const QImage& image) = 0;
		/*
		* @brief 向图像窗口添加ROI
		* @param roi 要添加的ROI对象
		* @return None
		*/
		virtual void AddRoi(const std::weak_ptr<MVRoi::IRoi> roi) = 0;
	};

	class IMAGE_WIDGET_API WindowFactory
	{
	public:
		/*
		* @brief 创建QImageWidget窗口实例
		* @param parent 父窗口指针
		* @return QImageWidgetInterface* 返回QImageWidget窗口的接口指针
		*/
		static QImageWidgetInterface* CreateQImageWidget(QWidget* parent = nullptr);
	};
}

#endif 

