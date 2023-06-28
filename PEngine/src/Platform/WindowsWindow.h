#pragma once

#include "PEngine/Window.h"

#include <GLFW/glfw3.h>

namespace PEngine
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow() override;

		virtual void OnUpdate() override;

		virtual inline unsigned int GetWidth() const override { return m_Data.Width; }
		virtual inline unsigned int GetHeight() const override { return m_Data.Height; }

		virtual inline void SetEventCallback(const EventCallbackFunc& callback) override { m_Data.EventCallback = callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;

			bool VSync;

			EventCallbackFunc EventCallback;
		};

		WindowData m_Data;
	};
}