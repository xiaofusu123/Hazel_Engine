#include "hzpch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "hazel/Events/Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "hazel/Events/Platform/OpenGL/imgui_impl_glfw.h"

#include "Hazel/Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Hazel
{

    ImGuiLayer::ImGuiLayer()
        : Layer("ImGuiLayer")
    {

    }

    ImGuiLayer::~ImGuiLayer()
    {

    }

    void ImGuiLayer::OnAttach()
    {
        IMGUI_CHECKVERSION();

        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;

        //io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
        //io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
        //io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
        //io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
        //io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
        //io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
        //io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
        //io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
        //io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
        //io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
        //io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        //io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
        //io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
        //io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
        //io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
        //io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
        //io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
        //io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
        //io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
        //io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
        //io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
        //io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

        ImGui::StyleColorsDark();

        Application& app = Application::Get();
        GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

        ImGui_ImplGlfw_InitForOpenGL(window, false);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach()
    {

    }

    void ImGuiLayer::OnUpdate()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        float time = (float)glfwGetTime();
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::UpdateModifierKeys()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

        bool leftCtrl = glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS;
        bool rightCtrl = glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS;
        bool leftShift = glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS;
        bool rightShift = glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS;
        bool leftAlt = glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS;
        bool rightAlt = glfwGetKey(window, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS;

        io.AddKeyEvent(ImGuiKey_LeftCtrl, leftCtrl);
        io.AddKeyEvent(ImGuiKey_RightCtrl, rightCtrl);
        io.AddKeyEvent(ImGuiKey_LeftShift, leftShift);
        io.AddKeyEvent(ImGuiKey_RightShift, rightShift);
        io.AddKeyEvent(ImGuiKey_LeftAlt, leftAlt);
        io.AddKeyEvent(ImGuiKey_RightAlt, rightAlt);

        io.KeyCtrl = leftCtrl || rightCtrl;
        io.KeyShift = leftShift || rightShift;
        io.KeyAlt = leftAlt || rightAlt;
    }

    ImGuiKey KeyCodeToImGuiKey(int keycode)
    {
        switch (keycode)
        {
            case GLFW_KEY_A: return ImGuiKey_A;
            case GLFW_KEY_B: return ImGuiKey_B;
            case GLFW_KEY_C: return ImGuiKey_C;
            case GLFW_KEY_D: return ImGuiKey_D;
            case GLFW_KEY_E: return ImGuiKey_E;
            case GLFW_KEY_F: return ImGuiKey_F;
            case GLFW_KEY_G: return ImGuiKey_G;
            case GLFW_KEY_H: return ImGuiKey_H;
            case GLFW_KEY_I: return ImGuiKey_I;
            case GLFW_KEY_J: return ImGuiKey_J;
            case GLFW_KEY_K: return ImGuiKey_K;
            case GLFW_KEY_L: return ImGuiKey_L;
            case GLFW_KEY_M: return ImGuiKey_M;
            case GLFW_KEY_N: return ImGuiKey_N;
            case GLFW_KEY_O: return ImGuiKey_O;
            case GLFW_KEY_P: return ImGuiKey_P;
            case GLFW_KEY_Q: return ImGuiKey_Q;
            case GLFW_KEY_R: return ImGuiKey_R;
            case GLFW_KEY_S: return ImGuiKey_S;
            case GLFW_KEY_T: return ImGuiKey_T;
            case GLFW_KEY_U: return ImGuiKey_U;
            case GLFW_KEY_V: return ImGuiKey_V;
            case GLFW_KEY_W: return ImGuiKey_W;
            case GLFW_KEY_X: return ImGuiKey_X;
            case GLFW_KEY_Y: return ImGuiKey_Y;
            case GLFW_KEY_Z: return ImGuiKey_Z;

            case GLFW_KEY_0: return ImGuiKey_0;
            case GLFW_KEY_1: return ImGuiKey_1;
            case GLFW_KEY_2: return ImGuiKey_2;
            case GLFW_KEY_3: return ImGuiKey_3;
            case GLFW_KEY_4: return ImGuiKey_4;
            case GLFW_KEY_5: return ImGuiKey_5;
            case GLFW_KEY_6: return ImGuiKey_6;
            case GLFW_KEY_7: return ImGuiKey_7;
            case GLFW_KEY_8: return ImGuiKey_8;
            case GLFW_KEY_9: return ImGuiKey_9;

            case GLFW_KEY_F1: return ImGuiKey_F1;
            case GLFW_KEY_F2: return ImGuiKey_F2;
            case GLFW_KEY_F3: return ImGuiKey_F3;
            case GLFW_KEY_F4: return ImGuiKey_F4;
            case GLFW_KEY_F5: return ImGuiKey_F5;
            case GLFW_KEY_F6: return ImGuiKey_F6;
            case GLFW_KEY_F7: return ImGuiKey_F7;
            case GLFW_KEY_F8: return ImGuiKey_F8;
            case GLFW_KEY_F9: return ImGuiKey_F9;
            case GLFW_KEY_F10: return ImGuiKey_F10;
            case GLFW_KEY_F11: return ImGuiKey_F11;
            case GLFW_KEY_F12: return ImGuiKey_F12;

            case GLFW_KEY_UP: return ImGuiKey_UpArrow;
            case GLFW_KEY_DOWN: return ImGuiKey_DownArrow;
            case GLFW_KEY_LEFT: return ImGuiKey_LeftArrow;
            case GLFW_KEY_RIGHT: return ImGuiKey_RightArrow;
            case GLFW_KEY_PAGE_UP: return ImGuiKey_PageUp;
            case GLFW_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
            case GLFW_KEY_HOME: return ImGuiKey_Home;
            case GLFW_KEY_END: return ImGuiKey_End;
            case GLFW_KEY_INSERT: return ImGuiKey_Insert;
            case GLFW_KEY_DELETE: return ImGuiKey_Delete;

            case GLFW_KEY_BACKSPACE: return ImGuiKey_Backspace;
            case GLFW_KEY_SPACE: return ImGuiKey_Space;
            case GLFW_KEY_ENTER: return ImGuiKey_Enter;
            case GLFW_KEY_ESCAPE: return ImGuiKey_Escape;
            case GLFW_KEY_TAB: return ImGuiKey_Tab;
            case GLFW_KEY_CAPS_LOCK: return ImGuiKey_CapsLock;

            case GLFW_KEY_LEFT_SHIFT: return ImGuiKey_LeftShift;
            case GLFW_KEY_RIGHT_SHIFT: return ImGuiKey_RightShift;
            case GLFW_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
            case GLFW_KEY_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
            case GLFW_KEY_LEFT_ALT: return ImGuiKey_LeftAlt;
            case GLFW_KEY_RIGHT_ALT: return ImGuiKey_RightAlt;
            case GLFW_KEY_LEFT_SUPER: return ImGuiKey_LeftSuper;
            case GLFW_KEY_RIGHT_SUPER: return ImGuiKey_RightSuper;

            default: return ImGuiKey_None;
        }
    }

    void ImGuiLayer::OnEvent(Event& event)
    {
        EventDispatcher dispacher(event);
        dispacher.Dispatch<MouseButtonPressedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
        dispacher.Dispatch<MouseButtonReleasedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
        dispacher.Dispatch<MouseMovedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
        dispacher.Dispatch<MouseScrolledEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
        dispacher.Dispatch<KeyPressedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
        dispacher.Dispatch<KeyTypedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
        dispacher.Dispatch<KeyReleasedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
        dispacher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
    }

    bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = true;

        return false;
    }

    bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = false;

        return false;
    }

    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(e.GetX(), e.GetY());

        return false;
    }

    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheelH += e.GetXOffset();
        io.MouseWheel += e.GetYOffset();

        return false;
    }

    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        ImGuiKey imgui_key = KeyCodeToImGuiKey(e.GetKeyCode());

        if (imgui_key != ImGuiKey_None)
        {
            io.AddKeyEvent(imgui_key, true);
        }

        UpdateModifierKeys();
        return false;
    }

    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        ImGuiKey imgui_key = KeyCodeToImGuiKey(e.GetKeyCode());

        if (imgui_key != ImGuiKey_None)
        {
            io.AddKeyEvent(imgui_key, false);
        }

        UpdateModifierKeys();
        return false;
    }

    bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        int keycode = e.GetKeyCode();
        if (keycode > 0 && keycode < 0x10000)
            io.AddInputCharacter((unsigned int)keycode);

        return false;
    }

    bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, e.GetWidth(), e.GetHeight());

        return false;
    }

}