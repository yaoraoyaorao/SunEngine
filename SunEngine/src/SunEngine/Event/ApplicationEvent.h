#pragma once

#include "Event.h"

namespace SunEngine {

	/// <summary>
	/// ���ڵ�����С�¼�
	/// </summary>
	class SUN_API WindowResizeEvent :public Event {
	public:
		WindowResizeEvent(unsigned int width,unsigned int height)
			: m_Width(width), m_Height(height) {}
		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }
		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << "," << m_Height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	/// <summary>
	/// ���ڹر��¼�
	/// </summary>
	class SUN_API WindowCloseEvent :public Event {
	public:
		WindowCloseEvent(){}
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	/// <summary>
	/// ����Tick�¼�
	/// </summary>
	class SUN_API AppTickEvent :public Event {
	public:
		AppTickEvent(){}
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	/// <summary>
	/// ��������¼�
	/// </summary>
	class SUN_API AppUpdateEvent :public Event {
	public:
		AppUpdateEvent(){}
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	/// <summary>
	/// ������Ⱦ�¼�
	/// </summary>
	class SUN_API AppRenderEvent :public Event {
	public:
		AppRenderEvent(){}
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}