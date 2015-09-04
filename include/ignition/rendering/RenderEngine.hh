/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef _IGNITION_RENDERING_RENDERENGINE_HH_
#define _IGNITION_RENDERING_RENDERENGINE_HH_

#include <string>
#include "ignition/rendering/RenderTypes.hh"
#include "ignition/rendering/Util.hh"

namespace ignition
{
  namespace rendering
  {
    /// \class RenderEngine RenderEngine.hh ignition/rendering/RenderEngine.hh
    /// \brief An abstract interface to a concrete render-engine. A
    /// RenderEngine is responsible for initializing a render-engine as well as
    /// creating, storing, and destroying scenes.
    class IGNITION_VISIBLE RenderEngine
    {
      /// \brief Deconstructor
      public: virtual ~RenderEngine() { }

      /// \brief Load any necessary resources to set up render-engine. This
      /// should called before any other function.
      /// \return True if the render-engine was successfully loaded
      public: virtual bool Load() = 0;

      /// \brief Initialize the render-engine. This should be called immediately
      /// after a successful call to Load.
      /// \return True if the render-engine was successfully initialized
      public: virtual bool Init() = 0;

      /// \brief Destroys all scenes created by render-engine and releases all
      /// loaded resources. This should be called when the given render-engine
      /// will no longer be used during runtime.
      /// \return True if the render-engine was successfully destroyed
      public: virtual void Destroy() = 0;

      // TODO: merge with Destroy
      public: virtual bool Fini() = 0;

      /// \brief Determines if the render-engine has been loaded.
      /// \return True if the render-engine is loaded
      public: virtual bool IsLoaded() const = 0;

      /// \brief Determines if the render-engine has been initialized.
      /// \return True if the render-engine is initialized
      public: virtual bool IsInitialized() const = 0;

      /// \brief Determines if the render-engine can be used. Despite loading
      /// and initializing the render-engine, it may not be possible to use due
      /// to hardware capabilities of the runtime system.
      /// \return True if the render-engine can be used
      public: virtual bool IsEnabled() const = 0;

      /// \brief Get name of the render-engine.
      /// \return The render-engine name
      public: virtual std::string GetName() const = 0;

      /// \brief Get the number of scenes actively managed by this
      /// render-engine
      /// \return The number of active scenes
      public: virtual unsigned int GetSceneCount() const = 0;

      /// \brief Determine if the given scene is actively managed by this
      /// render-engine
      /// \param[in] _scene Scene in question
      /// \return True if the scene is managed by this render-engine
      public: virtual bool HasScene(ConstScenePtr _scene) const = 0;

      /// \brief Determine if this render-engine manages the scene with the
      /// given ID.
      /// \param[in] _id ID of scene in question
      /// \return True if this render-engine manages the specified scene
      public: virtual bool HasSceneId(unsigned int _id) const = 0;

      /// \brief Determine if this render-engine manages the scene with the
      /// given name.
      /// \param[in] _name Name of scene in question
      /// \return True if this render-engine manages the specified scene
      public: virtual bool HasSceneName(const std::string &_name) const = 0;

      /// \brief Get the scene with the given ID. If no scenes exist with the
      /// given ID, NULL will be returned.
      /// \param[in] _id ID of scene to be retrieved
      /// \return The specified scene
      public: virtual ScenePtr GetSceneById(unsigned int _id) const = 0;

      /// \brief Get the scene with the given name. If no scenes exist with the
      /// given name, NULL will be returned.
      /// \param[in] _name Name of scene to be retrieved
      /// \return The specified scene
      public: virtual ScenePtr GetSceneByName(
                  const std::string &_name) const = 0;

      /// \brief Get the scene at the given index. If no scenes exist at the
      /// given index, NULL will be returned.
      /// \param[in] _index Index of scene
      /// \return The specified scene
      public: virtual ScenePtr GetSceneByIndex(unsigned int _index) const = 0;

      /// \brief Destroy the given scene. If the given scene is not managed by
      /// this render-engine, no work will be done.
      /// \param[in] _scene Scene to be destroyed
      public: virtual void DestroyScene(ScenePtr _scene) = 0;

      /// \brief Destroy the scene with the given ID. If no scenes exist at the
      /// given ID, no work will be done.
      /// \param[in] _id ID of the scene to destroy
      public: virtual void DestroySceneById(unsigned int _id) = 0;

      /// \brief Destroy the scene with the given name. If no scenes exist at
      /// the given name, no work will be done.
      /// \param[in] _name Name of the scene to destroy
      public: virtual void DestroySceneByName(const std::string &_name) = 0;

      /// \brief Destroy the scene at the given index. If no scenes exist at the
      /// given index, no work will be done.
      /// \param[in] _index Index of the scene to destroy
      public: virtual void DestroySceneByIndex(unsigned int _index) = 0;

      /// \brief Destroy all scenes managed by this render-engine
      public: virtual void DestroyScenes() = 0;

      /// \brief Create a new scene with the given name. The given name should
      /// be unique across all scenes managed by this render-engine. If a
      /// duplicate name is given, NULL will be returned. An unique ID will
      /// automatically be assigned to the created scene.
      /// \param[in] _name Name of the new scene
      /// \return The created scene
      public: virtual ScenePtr CreateScene(const std::string &_name) = 0;

      /// \brief Create a new scene with the given ID. The given ID should
      /// be unique across all scenes managed by this render-engine. If a
      /// duplicate ID is given, NULL will be returned. An unique name will
      /// automatically be assigned to the created scene.
      /// \param[in] _id ID of the new scene
      /// \param[in] _name Name of the new scene
      /// \return The created scene
      public: virtual ScenePtr CreateScene(unsigned int _id,
                  const std::string &_name) = 0;
    };
  }
}
#endif
