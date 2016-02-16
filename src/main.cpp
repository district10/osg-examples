#include "add_models.h"
#include "animate_switch.h"
#include "animation_path.h"
#include "apply_fog.h"
#include "basic_shape.h"
#include "bezier_shader.h"
#include "billboard.h"
#include "callback.h"
#include "cartoon_shader.h"
#include "channels.h"
#include "character_system.h"
#include "commandline.h"
#include "create_light.h"
#include "demo.h"
#include "driving_cessna.h"
#include "dynamic_geometry.h"
#include "face_colloctor.h"
#include "fade_in.h"
#include "fog.h"
#include "hud_camera.h"
#include "hudtext.h"
#include "inherit_attribute.h"
#include "lod_models.h"
#include "multisampling.h"
#include "notifier.h"
#include "occluders.h"
#include "octahedron.h"
#include "osg_win32.h"
#include "outlined_model.h"
#include "particle_fountain.h"
#include "proxy_loading.h"
#include "quad.h"
#include "quad_tree.h"
#include "readerwriter.h"
#include "receiver_thread.h"
#include "referenced.h"
#include "render_scenes.h"
#include "render_to_texture.h"
#include "select_geometry.h"
#include "serializer.h"
#include "set_attribute.h"
#include "shadow_of_cessna.h"
#include "sharing_textures.h"
#include "simulation_loop.h"
#include "spotlight.h"
#include "switch_node.h"
#include "teapod.h"
#include "tessellating.h"
#include "text3d.h"
#include "texture.h"
#include "texture_mapping.h"
#include "thread_models.h"
#include "timer.h"
#include "traits.h"
#include "transform_node.h"
#include "translucent.h"
#include "use_root.h"
#include "use_stereo.h"
#include "visit_model.h"

namespace ns { // namespace
    namespace cs { // character system
        int ac = 2;
        char *av[] = {
            "character_system_main",
            "--list"
        };
    }
    namespace cmd { // commandline
        int ac = 3;
        char *av[] = {
            "commandline",
            "--model",
            "cow.osg"
        };
    }
}

int main( int argc, char **argv )
{
    do {
        int mode = -1;
        printf( "\nselect: " );
        scanf( "%d", &mode );
        switch (mode) {
        case  1: add_models_main( argc, argv ); break;
        case  2: animate_switch_main( argc, argv ); break;
        case  3: animation_path_main( argc, argv ); break;
        case  4: apply_fog_main( argc, argv ); break;
        case  5: basic_shape_main( argc, argv ); break;
        case  6: bezier_shader_main( argc, argv ); break;
        case  7: billboard_main( argc, argv ); break;
        case  8: callback_main( argc, argv ); break;
        case  9: cartoon_shader_main( argc, argv ); break;
        case 10: channels_main( argc, argv ); break;
        case 11: character_system_main( ns::cs::ac, ns::cs::av ); break;
        case 12: commandline_main( ns::cmd::ac, ns::cmd::av ); break;
        case 13: create_light_main( argc, argv ); break;
        case 14: demo_main( argc, argv ); break;
        case 15: driving_cessna_main( argc, argv ); break;
        case 16: dynamic_geometry_main( argc, argv ); break;
        case 17: face_collector_main( argc, argv ); break;
        case 18: fade_in_main( argc, argv ); break;
        case 19: fog_main( argc, argv ); break;
        case 20: hud_carema_main( argc, argv ); break;
        case 21: hudtext_main( argc, argv ); break;
        case 22: inherit_attribute_main( argc, argv ); break;
        case 23: lod_models_main( argc, argv ); break;
        case 25: multisampling_main( argc, argv ); break;
        case 26: notifier_main( argc, argv ); break;
        case 27: occluders_main( argc, argv ); break;
        case 28: octahedron_main( argc, argv ); break;
        case 29: osg_win32_main( argc, argv ); break;
        case 30: outlined_model_main( argc, argv ); break;
        case 31: particle_fountain_main( argc, argv ); break;
        case 32: proxy_loading_main( argc, argv ); break;
        case 33: quad_main( argc, argv ); break;
        case 34: quad_tree_main( argc, argv ); break;
        // case 35: readerwriter_main( argc, argv ); break;
        case 36: receiver_thread_main( argc, argv ); break;
        case 37: referenced_main( argc, argv ); break;
        case 38: render_scenes_main( argc, argv ); break;
        case 39: render_to_texture_main( argc, argv ); break;
        case 40: select_geometry_main( argc, argv ); break;
        case 41: serializer_main( argc, argv ); break;
        case 42: set_attribute_main( argc, argv ); break;
        case 43: shadow_of_cessna_main( argc, argv ); break;
        case 44: sharing_textures_main( argc, argv ); break;
        case 45: simulation_loop_main( argc, argv ); break;
        case 46: spotlight_main( argc, argv ); break;
        case 47: switch_node_main( argc, argv ); break;
        case 48: teapod_main( argc, argv ); break;
        case 49: tessellating_main( argc, argv ); break;
        case 50: text3d_main( argc, argv ); break;
        case 51: texture_main( argc, argv ); break;
        case 52: texture_mapping_main( argc, argv ); break;
        case 53: thread_models_main( argc, argv ); break;
        case 54: timer_main( argc, argv ); break;
        case 55: traits_main( argc, argv ); break;
        case 56: transform_node_main( argc, argv ); break;
        case 57: translucent_main( argc, argv ); break;
        case 58: use_root_main( argc, argv ); break;
        case 59: use_stereo_main( argc, argv ); break;
        case 60: visit_model_main( argc, argv ); break;
        default: return -1;
        }
    } while (1);
}